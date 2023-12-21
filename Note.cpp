#include "Note.h"
#include <iostream>
#include <ctime>

using namespace std;

string Note::dateToString(const vector<int>& date) {
    string dateString;
    dateString += (date[0] < 10 ? "0" : "") + to_string(date[0]) + "-";
    dateString += (date[1] < 10 ? "0" : "") + to_string(date[1]) + "-";
    dateString += to_string(date[2]);
    return dateString;
}

std::vector<int> Note::stringToDate(const std::string& date) {
    const int pos = date.find("-");
    const int rpos = date.rfind("-");

    return vector({
        stoi(date.substr(0, pos)),
        stoi(date.substr(pos + 1, rpos - pos)),
        stoi(date.substr(rpos + 1))
    });
}

void Note::setCreateDate() {
    const time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    this->createDate = vector({ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year});
}

Note::Note() = default;

Note::Note(
    const string& firstname,
    const string& lastname,
    const string& phone,
    const string& description,
    const string& birthDate
) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->phone = phone;

    if (!description.empty())
        this->description = description;
    if (!birthDate.empty())
        this->birthDate = Note::stringToDate(birthDate);
    this->setCreateDate();
}

Note::~Note() = default;

string Note::getFirstname() {
    return this->firstname;
}

string Note::getLastname() {
    return this->lastname;
}

std::string Note::getPhone() {
    return this->phone;
}

std::string Note::getDescription() {
    return this->description;
}

std::string Note::getCreateDate() const {
    return Note::dateToString(this->createDate);
}

std::string Note::getBirthDate() const {
    return Note::dateToString(this->birthDate);
}

std::string Note::toString() {
    string str;
    str += this->getFirstname() + " " + this->getLastname() + " | " + this->getPhone() + "\n";
    str += "Описание: " + this->getDescription() + "\n";
    str += "Дата создания: " + this->getCreateDate() + "\n";

    const vector<int> date = this->getBirthDateAsVector();
    if (date.size() == 3 && date[0] > 0 && date[1] > 0 && date[2] > 0)
        str += "Дата рождения: " + this->getBirthDate() + "\n";
    return str;
}

std::vector<int> Note::getCreateDateAsVector() {
    return this->createDate;
}

std::vector<int> Note::getBirthDateAsVector() {
    return this->birthDate;
}

int Note::getCreateDateDay() const {
    return this->createDate[0];
}

int Note::getCreateDateMonth() const {
    return this->createDate[1];
}

int Note::getCreateDateYear() const {
    return this->createDate[2];
}

int Note::getBirthDateDay() const {
    return this->birthDate[0];
}

int Note::getBirthDateMonth() const {
    return this->birthDate[1];
}

int Note::getBirthDateYear() const {
    return this->birthDate[2];
}

std::istream& operator>>(std::istream& in, Note& ob) {
    cout << "Введите имя: ";
    in >> ob.firstname;

    cout << "Введите фамилию: ";
    in >> ob.lastname;

    cout << "Введите номер телефона: ";
    in >> ob.phone;

    string birthDate;
    cout << "Введите дату рождения [dd-mm-YYYY] (если её нет, то поставьте '-'): ";
    in >> birthDate;

    cout << "Введите описание (если его нет, то поставьте '-'): ";
    in.get();
    getline(in, ob.description);

    if (ob.description == "-")
        ob.description = "нет";
    if (birthDate != "-")
        ob.birthDate = Note::stringToDate(birthDate);
    ob.setCreateDate();

    return in;
}

std::ostream& operator<<(std::ostream& out, Note& ob) {
    out << ob.toString();
    return out;
}
