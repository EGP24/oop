#include "Set.h"
#include "SetTest.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    auto start = chrono::steady_clock::now();

    testSet();

    Set<int> a({});
    a.print();

    a.add(1);
    a.add(2);
    a.add(1);
    a.print();

    a.remove(2);
    a.print();

    a.clear();
    a.print();

    auto end = chrono::steady_clock::now();
    cout << "Затраченное время: ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " миллисекунд" << endl;
}
