#include "TestTriangle.h"
#include "Triangle.h"
#include "LogDuration.h"
#include <string>
#include <cassert>

using namespace std;


void testAreaTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    double result = triangle.area();

    // assert
    assert(result == 0.5);
}

void testIsIntersectTriangle() {
    // arrange
    int xs1[3] = {0, 0, 1};
    int ys1[3] = {0, 1, 0};
    Triangle triangle1(xs1, ys1, "Triangle1");

    int xs2[3] = {0, 0, 1};
    int ys2[3] = {0, 1, 0};
    Triangle triangle2(xs2, ys2, "Triangle2");

    // act
    bool result = triangle1.isIntersect(triangle2);

    // assert
    assert(result);
}

void testMoveTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    triangle.move(1, 1);

    // assert
    assert(triangle.getXs()[0] == 1);
    assert(triangle.getXs()[1] == 1);
    assert(triangle.getXs()[2] == 2);
    assert(triangle.getYs()[0] == 1);
    assert(triangle.getYs()[1] == 2);
    assert(triangle.getYs()[2] == 1);
}

void testIsPointInPolygonTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    bool result = triangle.isPointInPolygon(0, 0);

    // assert
    assert(result);
}

void testGetNameTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    string result = triangle.getName();

    // assert
    assert(result == "Triangle");
}

void testGetXsTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    int *result = triangle.getXs();

    // assert
    assert(result[0] == 0);
    assert(result[1] == 0);
    assert(result[2] == 1);
}

void testGetYsTriangle() {
    // arrange
    int xs[3] = {0, 0, 1};
    int ys[3] = {0, 1, 0};
    Triangle triangle(xs, ys, "Triangle");

    // act
    int *result = triangle.getYs();

    // assert
    assert(result[0] == 0);
    assert(result[1] == 1);
    assert(result[2] == 0);
}


void testTriangle() {
    LOG_DURATION("Test Triangle");
    testAreaTriangle();
    testIsIntersectTriangle();
    testMoveTriangle();
    testIsPointInPolygonTriangle();
    testGetNameTriangle();
    testGetXsTriangle();
    testGetYsTriangle();
}
