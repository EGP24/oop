#include "Matrix.h"
#include "MatrixTest.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    testMatrix();

    int choice = 20;
    do {
        cout << "1) Проверить является ли матрица квадратной\n";
        cout << "2) Проверить является ли матрица диагональной\n";
        cout << "3) Проверить является ли матрица нулевой\n";
        cout << "4) Проверить является ли матрица единичной\n";
        cout << "5) Проверить является ли матрица симметричной\n";
        cout << "7) Проверить является ли матрица верхней треугольой\n";
        cout << "8) Проверить является ли матрица нижней треугольной\n";
        cout << "9) Транспонировать матрицу\n";
        cout << "9) Возвести матрицу в степень\n";
        cout << "10) Получить обратную матрицу\n";
        cout << "11) Вычислить определитель матрицы\n";
        cout << "12) Вычислить нормы матрицы\n";
        cout << "13) Вычислить сумму двух матрицы\n";
        cout << "14) Вычислить разность двух матриц\n";
        cout << "15) Вычислить произведение двух матриц\n";
        cout << "16) Вычислить отношение двух матриц\n";
        cout << "17) Вычислить произведение матрицы и числа\n";
        cout << "18) Вычилисть отношение матрицы и числа\n";
        cout << "19) Сравнить две матрицы\n";
        cout << "20) Выйти\n";
        cout << "Введите номер команды для выполнения: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Matrix a;
                cout << "Матрица " << (a.isSquare() ? "" : "не ") << "является квадратной\n";
                continue;
            }
            case 2: {
                Matrix a;
                cout << "Матрица " << (a.isDiagonal() ? "" : "не ") << "является диагональной\n";
                continue;
            }
            case 3: {
                Matrix a;
                cout << "Матрица " << (a.isZeroMatrix() ? "" : "не ") << "является нулевой\n";
                continue;
            }
            case 4: {
                Matrix a;
                cout << "Матрица " << (a.isSingleMatix() ? "" : "не ") << "является единичной\n";
                continue;
            }
            case 5: {
                Matrix a;
                cout << "Матрица " << (a.isSymmetrical() ? "" : "не ") << "является симметричной\n";
                continue;
            }
            case 6: {
                Matrix a;
                cout << "Матрица " << (a.isTopTriangle() ? "" : "не ") << "является верхней треугольной\n";
                continue;
            }
            case 7: {
                Matrix a;
                cout << "Матрица " << (a.isBotTriangle() ? "" : "не ") << "является нижней треугольной\n";
                continue;
            }
            case 8: {
                Matrix a;
                cout << "Транспонированная матрица:\n";
                a.transposed().print();
                continue;
            }
            case 9: {
                Matrix a;
                cout << "Введите степень возведения матрицы: ";
                int c; cin >> c;
                cout << "Матрица в степени " << c << " :\n";
                a.power(c).print();
                continue;
            }
            case 10: {
                Matrix a;
                cout << "Обратная матрица:\n";
                a.reversed().print();
                continue;
            }
            case 11: {
                Matrix a;
                cout << "Определитель матрицы: " << a.determinant() << " \n";
                continue;
            }
            case 12: {
                Matrix a;
                for (int j = 0; auto i : a.norm())
                    cout << ++j << "-я норма: " << i << '\n';
                continue;
            }
            case 13: {
                Matrix a, b;
                cout << "Сумма двух матриц\n";
                (a + b).print();
                continue;
            }
            case 14: {
                Matrix a, b;
                cout << "Разность двух матриц\n";
                (a - b).print();
                continue;
            }
            case 15: {
                Matrix a, b;
                cout << "Произведение двух матриц\n";
                (a * b).print();
                continue;
            }
            case 16: {
                Matrix a, b;
                cout << "Отношение двух матриц\n";
                (a / b).print();
                continue;
            }
            case 17: {
                Matrix a;
                cout << "Введите число для произведения с матрицой: ";
                double b; cin >> b;
                cout << "Произведение матрицы и " << b << ":\n";
                (a * b).print();
                continue;
            }
            case 18: {
                Matrix a;
                cout << "Введите число для отношения с матрицой: ";
                double b; cin >> b;
                cout << "Отношение матрицы и " << b << ":\n";
                (a / b).print();
                continue;
            }
            case 19: {
                Matrix a, b;
                cout << "Матрицы " << (a == b ? "" : "не ") << "равны\n";
                continue;
            }
            case 20: {
                continue;
            }
            default: {
                cout << "Такой команды нет!\n";
            }
        }
    } while (choice != 20);
}
