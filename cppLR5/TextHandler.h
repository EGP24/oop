#pragma once
#include <vector>
#include <string>

class TextHandler {
    private:
        std::vector<std::string> sentences;
        std::string text;

    public:
        explicit TextHandler(const std::string& filename);

        static std::vector<std::string> splitToSentencesText(const std::string& text);

        static std::vector<std::string> getWordsOfSentence(const std::string& sentence);

        static int getCountOfWordInSentence(const std::string& sentence, const std::string& findWord);

        std::vector<std::string> getSentences();
};
