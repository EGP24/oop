#include "ZNAK.h"
#include "ZNAKTest.h"
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;


bool cmp(const ZNAK& z1, const ZNAK& z2) {
    string sign1 = z1.getZodiacSign(), sign2 = z2.getZodiacSign();
    return ranges::lexicographical_compare(sign1, sign2);
}

int main(int argc, char* argv[]) {
    auto start = chrono::steady_clock::now();

    testZNAK();

    setlocale(LC_ALL, "Russian");
    const int n = 8;
    ZNAK znaks[n];

    for (auto& i : znaks)
        cin >> i;
    sort(begin(znaks), end(znaks), cmp);


    cout << "Введите номер месяца для поиска: ";
    int currentMonth; cin >> currentMonth;
    bool findFlag = false;

    for (auto i : znaks) {
        if (i.getBirthMonth() == currentMonth) {
            findFlag = true;
            cout << i << '\n';
        }
    }

    if (!findFlag) {
        cout << "Людей с таким месяцем рождения не найдено.";
    }

    auto end = chrono::steady_clock::now();
    cout << "Затраченное время: ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " миллисекунд" << endl;
}
