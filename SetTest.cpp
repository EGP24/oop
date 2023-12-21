#include "SetTest.h"
#include "Set.h"
#include <cassert>

void testAdd() {
    // arrange
    Set<int> a({1, 2});

    // act
    a.add(3);

    // assert
    assert(a.hasItem(3));
}

void testRemove() {
    // arrange
    Set<int> a({1, 2});

    // act
    a.remove(2);

    // assert
    assert(!a.hasItem(2));
}

void testClear() {
    // arrange
    Set<int> a({1, 2});

    // act
    a.clear();

    // assert
    assert(a.length() == 0);
}

void testPop() {
    // arrange
    Set<int> a({1, 2});

    // act
    int removedElement = a.pop();

    // assert
    assert(removedElement == 2);
    assert(!a.hasItem(2));
}

void testHasItem() {
    // arrange
    Set<int> a({1, 2});

    // act
    bool resultA = a.hasItem(1), resultB = a.hasItem(3);

    // assert
    assert(resultA);
    assert(!resultB);
}

void testUnion() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    Set<int> result = a | b;

    // assert
    assert(result.hasItem(1));
    assert(result.hasItem(2));
    assert(result.hasItem(3));
}

void testIntersection() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    Set<int> result = a & b;

    // assert
    assert(result.hasItem(2));
}

void testDifference() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    Set<int> result = a - b;

    // assert
    assert(result.hasItem(1));
    assert(!result.hasItem(2));
    assert(!result.hasItem(3));
}

void testSymmetricDifference() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    Set<int> result = a ^ b;

    // assert
    assert(result.hasItem(1));
    assert(!result.hasItem(2));
    assert(result.hasItem(3));
}

void testUnionAssignment() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    a |= b;

    // assert
    assert(a.hasItem(1));
    assert(a.hasItem(2));
    assert(a.hasItem(3));
}

void testIntersectionAssignment() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    a &= b;

    // assert
    assert(a.hasItem(2));
}

void testDifferenceAssignment() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    a -= b;

    // assert
    assert(a.hasItem(1));
    assert(!a.hasItem(2));
    assert(!a.hasItem(3));
}

void testSymmetricDifferenceAssignment() {
    // arrange
    Set<int> a({1, 2}), b({2, 3});

    // act
    a ^= b;

    // assert
    assert(a.hasItem(1));
    assert(!a.hasItem(2));
    assert(a.hasItem(3));
}

void testEquals() {
    // arrange
    Set<int> a({1, 2}), b({1, 2});

    // act
    bool result = a == b;

    // assert
    assert(result);
}

void testNotEquals() {
    // arrange
    Set<int> a({1, 2}), b({1, 2});

    // act
    bool result = a != b;

    // assert
    assert(!result);
}

void testSubset() {
    // arrange
    Set<int> a({1, 2}), b({1, 2, 3});

    // act
    bool result = a < b;

    // assert
    assert(result);
}

void testSuperset() {
    // arrange
    Set<int> a({1, 2}), b({1, 2, 3});

    // act
    bool result = b > a;

    // assert
    assert(result);
}

void testProperSubset() {
    // arrange
    Set<int> a({1, 2}), b({1, 2, 3});

    // act
    bool result = a <= b;

    // assert
    assert(result);
}

void testProperSuperset() {
    // arrange
    Set<int> a({1, 2}), b({1, 2, 3});

    // act
    bool result = b >= a;

    // assert
    assert(result);
}

void testIterator() {
    // arrange
    Set<int> a({1, 2, 3});

    // act
    int sum = 0;
    for (auto i : a)
        sum += i;

    // assert
    assert(sum == 6);
}

void testSet() {
    testAdd();
    testRemove();
    testClear();
    testPop();
    testHasItem();
    testUnion();
    testIntersection();
    testDifference();
    testSymmetricDifference();
    testUnionAssignment();
    testIntersectionAssignment();
    testDifferenceAssignment();
    testSymmetricDifferenceAssignment();
    testEquals();
    testNotEquals();
    testSubset();
    testSuperset();
    testProperSubset();
    testProperSuperset();
    testIterator();
}