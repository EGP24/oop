#include "Note.h"
#include "NoteTest.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void testGetFirstname() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    string result = a.getFirstname();

    // assert
    assert(result == "John");
}

void testGetLastname() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    string result = a.getLastname();

    // assert
    assert(result == "Doe");
}

void testGetPhone() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    string result = a.getPhone();

    // assert
    assert(result == "89998887766");
}

void testGetDescription() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    string result = a.getDescription();

    // assert
    assert(result == "Description");
}

void testGetBirthDate() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    string result = Note::dateToString(a.getBirthDateAsVector());

    // assert
    assert(result == "11-11-2001");
}

void testGetBirthDateDay() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    int result = a.getBirthDateDay();

    // assert
    assert(result == 11);
}

void testGetBirthDateMonth() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    int result = a.getBirthDateMonth();

    // assert
    assert(result == 11);
}

void testGetBirthDateYear() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "");

    // act
    int result = a.getBirthDateYear();

    // assert
    assert(result == -1);
}

void testToString() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "");

    // act
    string result = a.toString();

    // assert
    result = result.substr(0, result.length() - 11);
    assert(result == "John Doe | 89998887766\nОписание: Description\nДата создания: ");
}

void testDateToString() {
    // arrange
    vector<int> date = {11, 11, 2001};

    // act
    string result = Note::dateToString(date);

    // assert
    assert(result == "11-11-2001");
}

void testStringToDate() {
    // arrange
    string date = "11-11-2001";

    // act
    vector<int> result = Note::stringToDate(date);

    // assert
    assert(result == vector<int>({11, 11, 2001}));
}

void testGetBirthDateAsVector() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description", "11-11-2001");

    // act
    vector<int> result = a.getBirthDateAsVector();

    // assert
    assert(result == vector<int>({11, 11, 2001}));
}

void testOperatorInput() {
    // arrange
    Note a("", "", "", "", "");
    stringstream ss("John Doe 89998887766 Description 11-11-2001");

    // act
    ss >> a;

    // assert
    assert(a.getFirstname() == "John");
    assert(a.getLastname() == "Doe");
    assert(a.getPhone() == "89998887766");
    assert(a.getDescription() == "Description");
    assert(Note::dateToString(a.getBirthDateAsVector()) == "11-11-2001");
}

void testOperatorOutput() {
    // arrange
    Note a("John", "Doe", "89998887766", "Description");
    stringstream ss;

    // act
    ss << a;

    // assert
    string result = ss.str().substr(0, ss.str().size() - 11);
    assert(result == "John Doe | 89998887766\nОписание: Description\nДата создания: ");
}

void testNote() {
    testGetFirstname();
    testGetLastname();
    testGetPhone();
    testGetDescription();
    testGetBirthDate();
    testGetBirthDateDay();
    testGetBirthDateMonth();
    testGetBirthDateYear();
    testToString();
    testDateToString();
    testStringToDate();
    testGetBirthDateAsVector();
    //testOperatorInput();
    testOperatorOutput();
}