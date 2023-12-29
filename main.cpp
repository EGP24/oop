#include "TextHandler.h"
#include "TextHandlerTest.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;


int main() {
    testTextHandler();

    setlocale(LC_ALL, "Russian");
    TextHandler handler("../test.txt");

    cout << "Введите искомое слово: ";
    string findWord; cin >> findWord;

    cout << "Предложение - Количество вхождений искомого слова\n";
    for (auto& sentence: handler.getSentences())
        cout << sentence.substr(1) << " - " << TextHandler::getCountOfWordInSentence(sentence, findWord) << '\n';
}
