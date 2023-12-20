#pragma once
#include "ZNAK.h"
#include <iostream>

using namespace std;

int utf8len(const string& s) {
    int len = 0;
    for (char c : s)
        if ((c & 0xC0) != 0x80)
            ++len;
    return len;
}

string zodiacSignsDisplayNames[12] = {
    string("овен"),
    string("телец"),
    string("близнецы"),
    string("рак"),
    string("лев"),
    string("дева"),
    string("весы"),
    string("скорпион"),
    string("стрелец"),
    string("козерог"),
    string("водолей"),
    string("рыбы")
};

ZNAK::ZNAK() = default;

ZNAK::ZNAK(string firstname, string lastname, int birthDay, int birthMonth, int birthYear, int zodiacSign) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->birthDay = birthDay;
    this->birthMonth = birthMonth;
    this->birthYear = birthYear;
    this->zodiacSign = zodiacSign;
}

ZNAK::~ZNAK() = default;

string ZNAK::getFirstName() const {
    return firstname;
}

string ZNAK::getLastName() const {
    return lastname;
}

string ZNAK::getZodiacSign() const {
    return zodiacSignsDisplayNames[zodiacSign];
}

int ZNAK::getBirthDay() const {
    return birthDay;
}

int ZNAK::getBirthMonth() const {
    return birthMonth;
}

int ZNAK::getBirthYear() const {
    return birthYear;
}

string ZNAK::getBirthDate() const {
    const string formattedBirthDay = (birthDay < 10 ? "0" : "") + to_string(birthDay);
    const string formattedBirthMonth = (birthMonth < 10 ? "0" : "") + to_string(birthMonth);
    
    return formattedBirthDay + "-" + formattedBirthMonth + "-" + to_string(birthYear);
}

istream& operator>>(istream& in, ZNAK& ob) {
    cout << "\nВведите данные в вормате:";
    cout << "\nФамилия Имя <Enter> Дата рождения [dd-mm-YYYY] <Enter>";
    cout << "\nНомер вашего знака зодиака в списке <Enter>";
    for (int i = 0; i < 3; ++i) {
        cout << "\n\t";
        for (int j = 0; j < 4; ++j) {
            string number = to_string(j * 3 + i + 1) + ")";
            string sign = zodiacSignsDisplayNames[j * 3 + i];
            for (;utf8len(sign) < 12; sign += " ") {}
            cout << number << " " << sign << "";
        }
    }
    cout << '\n';

    string birthDate;
    in >> ob.firstname >> ob.lastname >> birthDate >> ob.zodiacSign;

    const int pos = birthDate.find('-');
    const int rpos = birthDate.rfind('-');
    ob.birthDay = stoi(birthDate.substr(0, pos));
    ob.birthMonth = stoi(birthDate.substr(pos + 1, rpos - pos));
    ob.birthYear = stoi(birthDate.substr(rpos + 1));
    --ob.zodiacSign;

    return in;
}

ostream& operator<<(ostream& out, ZNAK& ob) {
    out << "Имя и фамилия: " << ob.getFirstName() << " " << ob.getLastName() << '\n';
    out << "Дата рождения: " << ob.getBirthDate() << '\n';
    out << "Знак зодиака:  " << ob.getZodiacSign() << '\n';

    return out;
}
