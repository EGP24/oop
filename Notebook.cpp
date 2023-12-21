#include "Notebook.h"
#include <iostream>

using namespace std;

bool compareDate(const vector<int>& date1, const vector<int>& date2) {
    return (
        date1[2] < date2[2]
        || date1[2] == date2[2] && date1[1] < date2[1]
        || date1[2] == date2[2] && date1[1] == date2[1] && date1[0] < date2[0]
    );
}

bool equalsDate(const vector<int>& date1, const vector<int>& date2) {
    return date1[0] == date2[0] && date1[1] == date2[1] && date1[2] == date2[2];
}

Notebook::Notebook() = default;

Notebook::Notebook(std::list<Note> notes) {
    this->notes = notes;
}

Notebook::~Notebook() = default;

std::list<Note> Notebook::selectNoteBy(
    const std::string& firstname,
    const std::string& lastname,
    const std::string& phone,
    const std::string& birthDay
) const {
    list<Note> result;

    for (auto note : notes) {
        if (
            (firstname.empty() || firstname == note.getFirstname())
            && (lastname.empty() || lastname == note.getLastname())
            && (phone.empty() || phone == note.getPhone())
            && (birthDay.empty() || birthDay == note.getBirthDate())
        ) {
            result.push_back(note);
        }
    }

    return result;
}

void Notebook::addNote(const Note& note) {
    this->notes.push_back(note);
}

void Notebook::deleteNoteBy(
    const std::string& firstname,
    const std::string& lastname,
    const std::string& phone,
    const std::string& birthDay
) {
    list<Note> newNotes = {};
    for (auto note : this->notes) {
        if (
            !((firstname.empty() || firstname == note.getFirstname())
            && (lastname.empty() || lastname == note.getLastname())
            && (phone.empty() || phone == note.getPhone())
            && (birthDay.empty() || birthDay == note.getBirthDate()))
        ) {
            newNotes.push_back(note);
        }
    }
    this->notes = newNotes;
}

void Notebook::deleteOldestNotes(const std::string& createDate) {
    list<Note> newNotes = {};
    const vector<int> date = Note::stringToDate(createDate);

    for (auto& note : this->notes) {
        if (!compareDate(note.getCreateDateAsVector(), date) || equalsDate(note.getCreateDateAsVector(), date))
            newNotes.push_back(note);
    }
    this->notes = newNotes;
}

void Notebook::deleteNewestNotes(const std::string& createDate) {
    list<Note> newNotes = {};
    const vector<int> date = Note::stringToDate(createDate);

    for (auto& note : this->notes) {
        if (compareDate(note.getCreateDateAsVector(), date) || equalsDate(note.getCreateDateAsVector(), date))
            newNotes.push_back(note);
    }
    this->notes = newNotes;
}

void Notebook::sortByFirstnameAsc() {
    this->notes.sort([](Note& a, Note& b) {
        return ranges::lexicographical_compare(a.getFirstname(), b.getFirstname());
    });
}

void Notebook::sortByFirstnameDesc() {
    this->notes.sort([](Note& a, Note& b) {
        return !ranges::lexicographical_compare(a.getFirstname(), b.getFirstname());
    });
}

void Notebook::sortByLastnameAsc() {
    this->notes.sort([](Note& a, Note& b) {
        return ranges::lexicographical_compare(a.getLastname(), b.getLastname());
    });
}

void Notebook::sortByLastnameDesc() {
    this->notes.sort([](Note& a, Note& b) {
        return !ranges::lexicographical_compare(a.getLastname(), b.getLastname());
    });
}

void Notebook::sortByBirthDateAsc() {
    this->notes.sort([](Note& a, Note& b) {
        return compareDate(a.getBirthDateAsVector(), b.getBirthDateAsVector());
    });
}

void Notebook::sortByBirthDateDesc() {
    this->notes.sort([](Note& a, Note& b) {
        return !compareDate(a.getBirthDateAsVector(), b.getBirthDateAsVector());
    });
}

void Notebook::sortByCreateDateAsc() {
    this->notes.sort([](Note& a, Note& b) {
        return compareDate(a.getCreateDateAsVector(), b.getCreateDateAsVector());
    });
}

void Notebook::sortByCreateDateDesc() {
    this->notes.sort([](Note& a, Note& b) {
        return !compareDate(a.getCreateDateAsVector(), b.getCreateDateAsVector());
    });
}

list<Note>::iterator Notebook::begin() {
    return this->notes.begin();
}

std::list<Note>::iterator Notebook::end() {
    return this->notes.end();
}

std::istream& operator>>(std::istream& in, Notebook& ob) {
    Note note; in >> note;
    ob.addNote(note);
    return in;
}

std::ostream& operator<<(std::ostream& out, Notebook& ob) {
    for (int i = 0; auto note : ob.notes) {
        out << ++i << ") ";
        out << note;
    }
    return out;
}
