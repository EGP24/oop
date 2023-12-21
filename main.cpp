#include "ZNAK.h"
#include "ZNAKTest.h"
#include <iostream>
#include <algorithm>

using namespace std;


bool cmp(const ZNAK& z1, const ZNAK& z2) {
    string sign1 = z1.getZodiacSign(), sign2 = z2.getZodiacSign();
    return ranges::lexicographical_compare(sign1, sign2);
}

int main(int argc, char* argv[]) {
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
}
