#include "TextHandlerTest.h"
#include "TextHandler.h"
#include "LogDuration.h"
#include <vector>
#include <string>

using namespace std;


void testSplitToSentencesText() {
    // arrange
    string text = "привет! как- дела))?\nхочу вафли";

    // act
    vector<string> result = TextHandler::splitToSentencesText(text);

    // assert
    assert(result.size() == 3);
    assert(result == vector<string>({"привет!", " как- дела))?", "\nхочу вафли."}));
}

void testGetWordsOfSentence() {
    // arrange
    string sentence = "привет! как- дела))?\nхочу вафли";

    // act
    vector<string> result = TextHandler::getWordsOfSentence(sentence);

    // assert
    assert(result.size() == 5);
    assert(result == vector<string>({"привет", "как", "дела", "хочу", "вафли"}));
}

void testGetCountOfWordInSentence() {
    // arrange
    string sentence = "приветпривет, привет как дела";

    // act
    int result = TextHandler::getCountOfWordInSentence(sentence, "привет");

    // assert
    assert(result == 1);
}

void testGetSentences() {
    // arrange
    TextHandler handler("../test.txt");

    // act
    vector<string> result = handler.getSentences();

    // assert
    assert(result.size() == 3);
    assert(result == vector<string>({" привет!", " как мне сделать вафли?", " подскажите рецепт пж."}));
}

void testTextHandler() {
    LOG_DURATION("Test Text Handler");
    testSplitToSentencesText();
    testGetWordsOfSentence();
    testGetCountOfWordInSentence();
    testGetSentences();
}
