#include "TestTriangle.h"
#include "TestTetragon.h"
#include "Factory.h"
#include "Menu.h"
#include <iostream>

using namespace std;


int main() {
    Factory factory;
    Menu menu;
    JobMode jobMode;

    testTriangle();
    testTetragon();

    while ((jobMode = menu.selectJob()) != JobExit) {
        switch (jobMode) {
            case AddObj: {
                factory.addFigure();
                continue;
            }
            case DelObj: {
                factory.removeFigure();
                continue;
            }
            case WorkWithObj: {
                FigureAction action;
                while ((action = menu.selectAction()) != ActionExit) {
                    switch (action) {
                        case GetArea: {
                            Polygon *polygon = menu.selectObject(factory);
                            if (polygon)
                                cout << "Площадь фигуры: " << polygon->area() << '\n';
                            break;
                        }
                        case IsIntersect: {
                            Polygon *polygon1 = menu.selectObject(factory);
                            Polygon *polygon2 = menu.selectObject(factory);
                            if (polygon1 && polygon2)
                                cout << "Фигуры " << (polygon1->isIntersect(*polygon2) ? "" : "не ") << "пересекаются\n";
                            break;
                        }
                        case Move: {
                            Polygon *polygon = menu.selectObject(factory);
                            if (polygon) {
                                cout << "Введите вектор сдвига в формате:\n";
                                cout << "[dx] [dy]\n";
                                cout << "Ваш ввод: ";
                                int dx, dy;
                                cin >> dx >> dy;
                                polygon->move(dx, dy);
                            }
                            break;
                        }
                        case ActionExit: {
                            break;
                        }
                    }
                }
            }
            case JobExit: {
                break;
            }
        }
    }
}
