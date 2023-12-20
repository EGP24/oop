#pragma once
#include "TextHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                 "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";


TextHandler::TextHandler(const string& filename) {
    fstream file;
    file.open(filename, ios::in);

    if (file.is_open()) {
        vector<string> lines;

        copy(
            istream_iterator<string>(file),
            istream_iterator<string>(),
            back_inserter(lines)
            );
        for (const auto& line: lines)
            this->text += " " + line;

        this->sentences = TextHandler::splitToSentencesText(this->text);
    }
}

vector<string> TextHandler::splitToSentencesText(const string& text) {
    vector<string> sentences;
    string sentence;
    for (auto symbol : text + ".") {
        sentence += symbol;
        if (
            string(".?!").find(symbol) != string::npos
            && sentence != "." && sentence != "!" && sentence != "?"
        ) {
            sentences.push_back(sentence);
            sentence = "";
        }
    }
    return sentences;
}

vector<string> TextHandler::getWordsOfSentence(const string& sentence) {
    vector<string> words;
    string word;

    for (const auto symbol : sentence + ".") {
        if (string(" .?!").find(symbol) != string::npos) {
            if (!word.empty())
                words.push_back(word);
            word = "";
        } else if (letters.find(symbol) != string::npos) {
            word += symbol;
        }
    }
    return words;
}

int TextHandler::getCountOfWordInSentence(const string& sentence, const string& findWord) {
    int count = 0;
    for (auto& word : TextHandler::getWordsOfSentence(sentence)) {
        if (word == findWord)
            count++;
    }
    return count;
}

vector<string> TextHandler::getSentences() {
    return this->sentences;
}
