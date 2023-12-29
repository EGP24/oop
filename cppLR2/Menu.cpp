#include "Menu.h"
#include <iostream>

using namespace std;


JobMode Menu::selectJob() const {
    cout << "==========================\n";
    cout << "Выберете действие:\n";
    cout << "1) Добавить фигуру\n";
    cout << "2) Удалить фигуру\n";
    cout << "3) Работать с фигурой\n";
    cout << "4) Выйти\n";
    cout << "==========================\n";
    int item = selectItem(4);
    return (JobMode) (item - 1);
}

Polygon *Menu::selectObject(const Factory &fctry) const {
    int nItem = fctry.polygons.size();
    if (!nItem) {
        cout << "Нет фигур для работы\n";
        return nullptr;
    }

    cout << "==========================\n";
    cout << "Выберете фигуру:\n";
    for (int i = 0; i < nItem; ++i)
        cout << i + 1 << ") " << fctry.polygons[i]->getName() << '\n';
    cout << "==========================\n";

    int item = selectItem(nItem);
    return fctry.polygons[item - 1];
}

int Menu::selectItem(int nItem) {
    int item;
    while (true) {
        cin >> item;
        if ((item > 0) && (item <= nItem) && cin.peek() == '\n') {
            cin.get();
            break;
        } else {
            cout << "Неверный ввод, попробуйте ещё раз\n";
            cin.clear();
            while (cin.get() != '\n') {}
        }
    }
    return item;
}

FigureAction Menu::selectAction() const {
    cout << "==========================\n";
    cout << "Выберете действие:\n";
    cout << "1) Получить площадь\n";
    cout << "2) Проверить пересечение\n";
    cout << "3) Сдвинуть\n";
    cout << "4) Выйти\n";
    cout << "==========================\n";
    int item = selectItem(4);
    return (FigureAction) (item - 1);
}
