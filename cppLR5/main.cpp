#include "TextHandler.h"
#include "TextHandlerTest.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;


int main() {
    auto start = chrono::steady_clock::now();

    testTextHandler();

    setlocale(LC_ALL, "Russian");
    TextHandler handler("../test.txt");

    cout << "Введите искомое слово: ";
    string findWord; cin >> findWord;

    cout << "Предложение - Количество вхождений искомого слова\n";
    for (auto& sentence: handler.getSentences())
        cout << sentence.substr(1) << " - " << TextHandler::getCountOfWordInSentence(sentence, findWord) << '\n';

    auto end = chrono::steady_clock::now();
    cout << "Затраченное время: ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " миллисекунд" << endl;
}
