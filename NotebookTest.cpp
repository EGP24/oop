#include "Notebook.h"
#include "Note.h"
#include <sstream>

using namespace std;

void testSelectNoteBy() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
    });

    // act
    list<Note> result = notebook.selectNoteBy(
        "John",
        "Doe",
        "+7 (999) 999-99-99",
        "01-01-2000"
    );

    // assert
    assert(result.size() == 5);
}

void testAddNote() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
    });

    // act
    notebook.addNote(
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    );

    // assert
    assert(notebook.selectNoteBy(
        "Jane",
        "Doe",
        "+7 (999) 999-99-99",
        "01-01-2000"
    ).size() == 1);
}

void testDeleteNoteBy() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
    });

    // act
    notebook.deleteNoteBy(
        "Jane",
        "Doe",
        "+7 (999) 999-99-99",
        "01-01-2000"
    );

    // assert
    assert(notebook.selectNoteBy(
        "Jane",
        "Doe",
        "+7 (999) 999-99-99",
        "01-01-2000"
    ).size() == 0);
}

void testSortByFirstnameAsc() {
    // arrange
    Notebook notebook({
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByFirstnameAsc();

    // assert
    assert(notebook.begin()->getFirstname() == "Jane");
}

void testSortByFirstnameDesc() {
    // arrange
    Notebook notebook({
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByFirstnameDesc();

    // assert
    assert(notebook.begin()->getFirstname() == "John");
}

void testSortByLastnameAsc() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Aoe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByLastnameAsc();

    // assert
    assert(notebook.begin()->getLastname() == "Aoe");
}

void testSortByLastnameDesc() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Aoe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByLastnameDesc();

    // assert
    assert(notebook.begin()->getLastname() == "Doe");
}

void testSortByBirthDateAsc() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "02-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByBirthDateAsc();

    // assert
    assert(notebook.begin()->getBirthDate() == "01-01-2000");
}

void testSortByBirthDateDesc() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "02-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        )
    });

    // act
    notebook.sortByBirthDateDesc();

    // assert
    assert(notebook.begin()->getBirthDate() == "02-01-2000");
}

void testNotebookOperatorInput() {
    // arrange
    Notebook notebook;
    stringstream ss("John Doe +7(999)999-99-99 01-01-2000");

    // act
    ss >> notebook;

    // assert
    assert(notebook.selectNoteBy(
        "John",
        "Doe",
        "+7(999)999-99-99",
        "01-01-2000"
    ).size() == 1);
}

void testNotebookOperatorOutput() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7(999)999-99-99"
        )
    });
    stringstream ss;

    // act
    ss << notebook;
    string reslut = ss.str().substr(0, ss.str().length() - 11);

    // assert
    assert(reslut == "1) John Doe | +7(999)999-99-99\nОписание: нет\nДата создания: ");
}

void testIterator() {
    // arrange
    Notebook notebook({
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "Jane",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
        Note(
            "John",
            "Doe",
            "+7 (999) 999-99-99",
            "",
            "01-01-2000"
        ),
    });

    // act
    int count = 0;
    for (auto i : notebook)
        count++;

    // assert
    assert(count == 6);
}

void testNotebook() {
    testSelectNoteBy();
    testAddNote();
    testDeleteNoteBy();
    testSortByFirstnameAsc();
    testSortByFirstnameDesc();
    testSortByLastnameAsc();
    testSortByLastnameDesc();
    testSortByBirthDateAsc();
    testSortByBirthDateDesc();
    //testNotebookOperatorInput();
    testNotebookOperatorOutput();
    testIterator();
}