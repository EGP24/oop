#include "MatrixTest.h"
#include "Matrix.h"
#include "LogDuration.h"
#include <cassert>

using  namespace std;


void testIsSquare() {
    // arrange
    Matrix a(2, 2, {{1, 1}, {1, 1}});
    Matrix b(2, 3, {{1, 1, 1}, {1, 1, 1}});

    // act
    bool resultA = a.isSquare(), resultB = b.isSquare();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsDiagonal() {
    // arrange
    const Matrix a(2, 2, {{1, 0}, {0, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isDiagonal(), resultB = b.isDiagonal();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsZeroMatrix() {
    // arrange
    const Matrix a(2, 2, {{0, 0}, {0, 0}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isZeroMatrix(), resultB = b.isZeroMatrix();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsSingleMatrix() {
    // arrange
    const Matrix a(2, 2, {{1, 0}, {0, 1}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isSingleMatix(), resultB = b.isSingleMatix();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsSymmetrical() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {2, 1}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isSymmetrical(), resultB = b.isSymmetrical();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsTopTriangle() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {0, 1}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isTopTriangle(), resultB = b.isTopTriangle();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testIsBotTriangle() {
    // arrange
    const Matrix a(2, 2, {{1, 0}, {2, 1}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool resultA = a.isBotTriangle(), resultB = b.isBotTriangle();

    // assert
    assert(resultA);
    assert(!resultB);
}

void testTransposed() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a.transposed();

    // assert
    assert(result == Matrix(2, 2, {{1, 3}, {2, 4}}));
}

void testPower() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result1 = a.power(2);
    Matrix result2 = a.power(-1);
    Matrix result3 = a.power(0);

    // assert
    assert(result1 == Matrix(2, 2, {{7, 10}, {15, 22}}));
    assert(result2 == Matrix(2, 2, {{-2, 1}, {1.5, -0.5}}));
    assert(result3 == Matrix(2, 2, {{1, 0}, {0, 1}}));
}

void testReversed() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a.reversed();

    // assert
    assert(result == Matrix(2, 2, {{-2, 1}, {1.5, -0.5}}));
}

void testDeterminant() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    double result = a.determinant();

    // assert
    assert(result == -2);
}

void testNorm() {
    // arrange
    const Matrix a(2, 3, {{2, 0, 1}, {0, 2, 4}});

    // act
    vDouble result = a.norm();

    // assert
    assert(result == vDouble({5, 6, 5}));
}

void testGetMatrixWithoutRowAndCol() {
    // arrange
    const Matrix a(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // act
    Matrix result = a.getMatrixWithoutRowAndCol(1, 1);

    // assert
    assert(result == Matrix(2, 2, {{1, 3}, {7, 9}}));
}

void testGetMatrix() {
    // arrange
    const Matrix a(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // act
    mVector result = a.getMatrix();

    // assert
    assert(result == mVector({vDouble({1, 2, 3}), vDouble({4, 5, 6}), vDouble({7, 8, 9})}));
}

void testGetRows() {
    // arrange
    const Matrix a(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // act
    int result = a.getRows();

    // assert
    assert(result == 3);
}

void testGetColumns() {
    // arrange
    const Matrix a(3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // act
    const int result = a.getColumns();

    // assert
    assert(result == 3);
}

void testOperatorPlus() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a + b;

    // assert
    assert(result == Matrix(2, 2, {{2, 4}, {6, 8}}));
}

void testOperatorMinus() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a - b;

    // assert
    assert(result == Matrix(2, 2, {{0, 0}, {0, 0}}));
}

void testOperatorMultiply() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a * b;

    // assert
    assert(result == Matrix(2, 2, {{7, 10}, {15, 22}}));
}

void testOperatorMultiplyByNumber() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a * 2;

    // assert
    assert(result == Matrix(2, 2, {{2, 4}, {6, 8}}));
}

void testOperatorDivide() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a / b;

    // assert
    assert(result == Matrix(2, 2, {{1, 0}, {0, 1}}));
}

void testOperatorDivideByNumber() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    Matrix result = a / 2;

    // assert
    assert(result == Matrix(2, 2, {{0.5, 1}, {1.5, 2}}));
}

void testOperatorEqual() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool result = a == b;

    // assert
    assert(result);
}

void testOperatorNotEqual() {
    // arrange
    const Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    bool result = a != b;

    // assert
    assert(!result);
}

void testOperatorPlusEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    a += b;

    // assert
    assert(a == Matrix(2, 2, {{2, 4}, {6, 8}}));
}

void testOperatorMinusEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    a -= b;

    // assert
    assert(a == Matrix(2, 2, {{0, 0}, {0, 0}}));
}

void testOperatorMultiplyEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    a *= b;

    // assert
    assert(a == Matrix(2, 2, {{7, 10}, {15, 22}}));
}

void testOperatorDivideEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});
    const Matrix b(2, 2, {{1, 2}, {3, 4}});

    // act
    a /= b;

    // assert
    assert(a == Matrix(2, 2, {{1, 0}, {0, 1}}));
}

void testOperatorMultiplyByNumberEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    a *= 2;

    // assert
    assert(a == Matrix(2, 2, {{2, 4}, {6, 8}}));
}

void testOperatorDivideByNumberEqual() {
    // arrange
    Matrix a(2, 2, {{1, 2}, {3, 4}});

    // act
    a /= 2;

    // assert
    assert(a == Matrix(2, 2, {{0.5, 1}, {1.5, 2}}));
}

void testMatrix() {
    LOG_DURATION("Test Matrix");
    testIsSquare();
    testIsDiagonal();
    testIsZeroMatrix();
    testIsSingleMatrix();
    testIsSymmetrical();
    testIsTopTriangle();
    testIsBotTriangle();
    testTransposed();
    testPower();
    testReversed();
    testDeterminant();
    testNorm();
    testGetMatrixWithoutRowAndCol();
    testGetMatrix();
    testGetRows();
    testGetColumns();
    testOperatorPlus();
    testOperatorMinus();
    testOperatorMultiply();
    testOperatorMultiplyByNumber();
    testOperatorDivide();
    testOperatorDivideByNumber();
    testOperatorEqual();
    testOperatorNotEqual();
    testOperatorPlusEqual();
    testOperatorMinusEqual();
    testOperatorMultiplyEqual();
    testOperatorDivideEqual();
    testOperatorMultiplyByNumberEqual();
    testOperatorDivideByNumberEqual();
}
