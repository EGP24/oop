#include "TestTetragon.h"
#include "Tetragon.h"
#include "LogDuration.h"
#include <cassert>

void testAreaTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    double result = tetragon.area();

    // assert
    assert(result == 2);
}

void testIsIntersectTetragon() {
    // arrange
    int xs1[4] = {0, 0, 1, 1};
    int ys1[4] = {0, 2, 2, 0};
    Tetragon tetragon1(xs1, ys1, "Tetragon1");

    int xs2[4] = {0, 0, 1, 1};
    int ys2[4] = {0, 2, 2, 0};
    Tetragon tetragon2(xs2, ys2, "Tetragon2");

    // act
    bool result = tetragon1.isIntersect(tetragon2);

    // assert
    assert(result);
}

void testMoveTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    tetragon.move(1, 1);

    // assert
    assert(tetragon.getXs()[0] == 1);
    assert(tetragon.getXs()[1] == 1);
    assert(tetragon.getXs()[2] == 2);
    assert(tetragon.getXs()[3] == 2);
    assert(tetragon.getYs()[0] == 1);
    assert(tetragon.getYs()[1] == 3);
    assert(tetragon.getYs()[2] == 3);
    assert(tetragon.getYs()[3] == 1);
}

void testIsPointInPolygonTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    bool result = tetragon.isPointInPolygon(0, 0);

    // assert
    assert(result);
}

void testGetNameTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    std::string result = tetragon.getName();

    // assert
    assert(result == "Tetragon");
}

void testGetXsTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    int *result = tetragon.getXs();

    // assert
    assert(result[0] == 0);
    assert(result[1] == 0);
    assert(result[2] == 1);
    assert(result[3] == 1);
}

void testGetYsTetragon() {
    // arrange
    int xs[4] = {0, 0, 1, 1};
    int ys[4] = {0, 2, 2, 0};
    Tetragon tetragon(xs, ys, "Tetragon");

    // act
    int *result = tetragon.getYs();

    // assert
    assert(result[0] == 0);
    assert(result[1] == 2);
    assert(result[2] == 2);
    assert(result[3] == 0);
}


void testTetragon() {
    LOG_DURATION("Test Tetragon");
    testAreaTetragon();
    testIsIntersectTetragon();
    testMoveTetragon();
    testIsPointInPolygonTetragon();
    testGetNameTetragon();
    testGetXsTetragon();
    testGetYsTetragon();
}
