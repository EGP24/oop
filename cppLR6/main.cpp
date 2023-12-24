#include "Note.h"
#include "Notebook.h"
#include "NoteTest.h"
#include "NotebookTest.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();

    testNote();
    testNotebook();

    Notebook notebook;
    int choice = 15;

    do {
        cout << "1) Добавить запись\n";
        cout << "2) Удалить запись\n";
        cout << "3) Показать все записи\n";
        cout << "4) Выбрать записи\n";
        cout << "5) Удалить записи старше даты\n";
        cout << "6) Удалить записи новее даты\n";
        cout << "7) Отсортировать записи по имени по возрастанию\n";
        cout << "8) Отсортировать записи по имени по убыванию\n";
        cout << "9) Отсортировать записи по фамилии по возрастанию\n";
        cout << "10) Отсортировать записи по фамилии по убыванию\n";
        cout << "11) Отсортировать записи по дате рождения по возрастанию\n";
        cout << "12) Отсортировать записи по дате рождения по убыванию\n";
        cout << "13) Отсортировать записи по дате создания по возрастанию\n";
        cout << "14) Отсортировать записи по дате создания по убыванию\n";
        cout << "15) Выйти\n";
        cout << "Выберете действие: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin >> notebook;
                continue;
            }
            case 2: {
                cout << "Введите параметры для поиск записей к удалению в формате:\n";
                cout << "[имя] [фамилия] [номер телефона] [дата рождения|dd-mm-YYY]\n";
                cout << "Если по какому-либо из параметров не нужно искать, введите \"-\"\n";

                string name, surname, phoneNumber, birthday;
                cin >> name >> surname >> phoneNumber >> birthday;
                name = name != "-" ? name : "";
                surname = surname != "-" ? surname : "";
                phoneNumber = phoneNumber != "-" ? phoneNumber : "";
                birthday = birthday != "-" ? birthday : "";

                notebook.deleteNoteBy(name, surname, phoneNumber, birthday);
                continue;
            }
            case 3: {
                cout << notebook;
                continue;
            }
            case 4: {
                cout << "Введите параметры для поиска записей в формате:\n";
                cout << "[имя] [фамилия] [номер телефона] [дата рождения|dd-mm-YYY]\n";
                cout << "Если по какому-либо из параметров не нужно искать, введите \"-\"\n";

                string name, surname, phoneNumber, birthday;
                cin >> name >> surname >> phoneNumber >> birthday;
                name = name != "-" ? name : "";
                surname = surname != "-" ? surname : "";
                phoneNumber = phoneNumber != "-" ? phoneNumber : "";
                birthday = birthday != "-" ? birthday : "";

                for (auto note : notebook.selectNoteBy(name, surname, phoneNumber, birthday))
                    cout << note << '\n';
                continue;
            }
            case 5: {
                cout << "Введите дату в формате [dd-mm-YYYY]: ";
                string date;
                cin >> date;
                notebook.deleteOldestNotes(date);
                continue;
            }
            case 6: {
                cout << "Введите дату в формате [dd-mm-YYYY]: ";
                string date;
                cin >> date;
                notebook.deleteNewestNotes(date);
                continue;
            }
            case 7: {
                notebook.sortByFirstnameAsc();
                continue;
            }
            case 8: {
                notebook.sortByFirstnameDesc();
                continue;
            }
            case 9: {
                notebook.sortByLastnameAsc();
                continue;
            }
            case 10: {
                notebook.sortByLastnameDesc();
                continue;
            }
            case 11: {
                notebook.sortByBirthDateAsc();
                continue;
            }
            case 12: {
                notebook.sortByBirthDateDesc();
                continue;
            }
            case 13: {
                notebook.sortByCreateDateAsc();
                continue;
            }
            case 14: {
                notebook.sortByCreateDateDesc();
                continue;
            }
            case 15: {
                break;
            }
        }
    } while (choice != 15);

    auto end = chrono::steady_clock::now();
    cout << "Затраченное время: ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " миллисекунд" << endl;
}
