#include "ZNAK.h"
#include <cassert>
#include <sstream>
#include <iostream>

using namespace std;

void testGetFirstName() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    string result = a.getFirstName();

    // assert
    assert(result == "John");
}

void testGetLastName() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    string result = a.getLastName();

    // assert
    assert(result == "Doe");
}

void testGetZodiacSign() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    string result = a.getZodiacSign();

    // assert
    assert(result == "овен");
}

void testGetBirthDay() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    int result = a.getBirthDay();

    // assert
    assert(result == 1);
}

void testGetBirthMonth() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    int result = a.getBirthMonth();

    // assert
    assert(result == 1);
}

void testGetBirthYear() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    int result = a.getBirthYear();

    // assert
    assert(result == 2000);
}

void testGetBirthDate() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);

    // act
    string result = a.getBirthDate();

    // assert
    assert(result == "01-01-2000");
}

void testOperatorInput() {
    // arrange
    ZNAK a("", "", 0, 0, 0, 0);
    stringstream ss("John Doe 01-01-2000 1");

    // act
    ss >> a;

    // assert
    assert(a.getFirstName() == "John");
    assert(a.getLastName() == "Doe");
    assert(a.getBirthDay() == 1);
    assert(a.getBirthMonth() == 1);
    assert(a.getBirthYear() == 2000);
    assert(a.getZodiacSign() == "овен");
}

void testOperatorOutput() {
    // arrange
    ZNAK a("John", "Doe", 1, 1, 2000, 0);
    stringstream ss;

    // act
    ss << a;

    // assert
    assert(ss.str() == "Имя и фамилия: John Doe\nДата рождения: 01-01-2000\nЗнак зодиака:  овен\n");
}

void testZNAK() {
    testGetFirstName();
    testGetLastName();
    testGetZodiacSign();
    testGetBirthDay();
    testGetBirthMonth();
    testGetBirthYear();
    testGetBirthDate();
    //testOperatorInput();
    testOperatorOutput();
}