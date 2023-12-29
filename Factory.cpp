#include "Menu.h"
#include "Factory.h"
#include "Triangle.h"
#include "Tetragon.h"
#include <iostream>

using namespace std;


Factory::Factory() = default;

Factory::~Factory() = default;

void Factory::addFigure() {
    cout << "==========================\n";
    cout << "Выберите тип фигуры:" << '\n';
    cout << "1) Треугольник" << '\n';
    cout << "2) Четырёхугольник" << '\n';
    cout << "3) Отмена" << '\n';
    cout << "==========================\n";
    int choice = Menu::selectItem(3);

    switch (choice) {
        case 1: {
            cout << "Введите координаты вершин треугольника в формате:\n";
            cout << "[x1] [y1] [x2] [y2] [x3] [y3]\n";
            cout << "Ваш ввод: ";
            int *xs = new int[3];
            int *ys = new int[3];
            for (int i = 0; i < 3; ++i) {
                cin >> xs[i] >> ys[i];
            }
            cout << "Введите название фигуры: ";
            string name; cin >> name;
            polygons.push_back(new Triangle(xs, ys, name));
            break;
        }
        case 2: {
            cout << "Введите координаты вершин четырёхугольника в формате:\n";
            cout << "[x1] [y1] [x2] [y2] [x3] [y3] [x4] [y4]\n";
            cout << "Ваш ввод: ";
            int *xs = new int[4];
            int *ys = new int[4];
            for (int i = 0; i < 4; ++i) {
                cin >> xs[i] >> ys[i];
            }
            cout << "Введите название фигуры: ";
            string name; cin >> name;
            polygons.push_back(new Tetragon(xs, ys, name));
            break;
        }
        case 3: {
            break;
        }
    }

}

void Factory::removeFigure() {
    if (!polygons.size()) {
        cout << "Нет фигур для удаления\n";
        return;
    }
    cout << "==========================\n";
    cout << "Выберите фигуру для удаления:" << '\n';
    for (int i = 0; i < polygons.size(); ++i)
        cout << i + 1 << ") " << polygons[i]->getName() << '\n';
    int item = Menu::selectItem(polygons.size());
    polygons.erase(polygons.begin() + item - 1);
    cout << "==========================\n";
}
