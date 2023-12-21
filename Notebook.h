#pragma once
#include <list>
#include "Note.h"

class Notebook {
private:
    std::list<Note> notes = {};
public:
    Notebook();
    explicit Notebook(std::list<Note> notes);
    ~Notebook();

    std::list<Note> selectNoteBy(
        const std::string& firstname = "",
        const std::string& lastname = "",
        const std::string& phone = "",
        const std::string& birthDay = ""
    ) const;

    void addNote(const Note& note);

    void deleteNoteBy(
        const std::string& firstname = "",
        const std::string& lastname = "",
        const std::string& phone = "",
        const std::string& birthDay = ""
    );
    void deleteOldestNotes(const std::string& createDate);
    void deleteNewestNotes(const std::string& createDate);

    void sortByFirstnameAsc();
    void sortByFirstnameDesc();
    void sortByLastnameAsc();
    void sortByLastnameDesc();
    void sortByBirthDateAsc();
    void sortByBirthDateDesc();
    void sortByCreateDateAsc();
    void sortByCreateDateDesc();

    std::list<Note>::iterator begin();
    std::list<Note>::iterator end();

    friend std::istream& operator>>(std::istream& in, Notebook& ob);
    friend std::ostream& operator<<(std::ostream& out, Notebook& ob);
};
