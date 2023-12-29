#include "Set.h"
#include "SetTest.h"

using namespace std;

int main(int argc, char* argv[])
{
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
}
