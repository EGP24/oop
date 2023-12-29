#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() {
    cout << "Введите количесвто строк: ";
    cin >> this->rows;

    cout << "Введите количесвто столбцов: ";
    cin >> this->columns;

    cout << "Введите вещетственные числа, элементы матрицы:\n";
    this->matrix = mVector(rows, vDouble(columns, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> this->matrix[i][j];
        }
    }
};

Matrix::Matrix(const int rows, const int columns, const mVector& matrix) {
    this->rows = rows;
    this->columns = columns;
    this->matrix = matrix;
}

Matrix::~Matrix() = default;

void Matrix::print() const {
    cout << "[";
    for (int i = 0; i < rows; ++i) {
        cout << "[";
        for (int j = 0; j < columns; ++j ) {
            cout << matrix[i][j];
            if (j != columns - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != rows - 1)
            cout << "," << '\n';
    }
    cout << "]" << '\n';
}

bool Matrix::isSquare() const {
    return rows == columns;
}

bool Matrix::isDiagonal() const {
    if (!this->isSquare())
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::isZeroMatrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::isSingleMatix() const {
    if (!this->isSquare())
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == j && matrix[i][j] != 1)
                return false;
            if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::isSymmetrical() const {
    if (!this->isSquare())
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}

bool Matrix::isTopTriangle() const {
    if (!this->isSquare())
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i > j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool Matrix::isBotTriangle() const {
    if (!this->isSquare())
        return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i < j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

Matrix Matrix::transposed() const {
    mVector newMatrix(columns, vDouble(rows, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    return Matrix(columns, rows, newMatrix);
}

Matrix Matrix::power(int n) const {
    Matrix newMatrix(rows, columns, this->getMatrix());
    if (n == 0) {
        mVector newMatrixArr(rows, vDouble(columns, 0));
        for (int i = 0; i < rows; ++i)
            newMatrixArr[i][i] = 1;
        return Matrix(rows, columns, newMatrixArr);
    } else if (n > 0) {
        for (int i = 1; i < n; ++i)
            newMatrix *= *this;
    } else if (n < 0) {
        newMatrix = newMatrix.reversed();
        for (int i = 1; i < n; ++i)
            newMatrix *= *this;
    }
    return newMatrix;
}

Matrix Matrix::reversed() const {
    double det = this->determinant();

    mVector newMatrix(columns, vDouble(rows, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            newMatrix[i][j] = pow(-1, i + j) * (1 / det) * this->getMatrixWithoutRowAndCol(i, j).determinant();
        }
    }

    return Matrix(rows, columns, newMatrix).transposed();
}


double Matrix::determinant() const {
    if (rows == 1)
        return matrix[0][0];

    double det = 0;
    int n = rows;

    for (int i = 0; i < n; i++)
        det += pow(-1, i) * matrix[0][i] * this->getMatrixWithoutRowAndCol(0, i).determinant();
    return det;
}

vDouble Matrix::norm() const {
    vDouble norms(3, 0);
    vDouble sums1(rows, 0);
    vDouble sums2(columns, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sums2[j] += abs(matrix[i][j]);
            sums1[i] += abs(matrix[i][j]);
            norms[2] += matrix[i][j] * matrix[i][j];
        }
    }

    norms[1] = *max_element(begin(sums1), end(sums1));
    norms[0] = *max_element(begin(sums2), end(sums2));
    norms[2] = sqrt(norms[2]);

    return norms;
}

Matrix Matrix::getMatrixWithoutRowAndCol(int row, int col) const {
    mVector newMatrix(rows - 1, vDouble(columns - 1, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == row || j == col)
                continue;
            newMatrix[i - (int) (i > row)][j - (int) (j > col)] = matrix[i][j];
        }
    }
    return Matrix(rows - 1, columns - 1, newMatrix);
}

int Matrix::getRows() const {
    return this->rows;
}

int Matrix::getColumns() const {
    return this->columns;
}

Matrix& Matrix::operator+=(const Matrix &a) {
    matrix = (*this + a).getMatrix();
    return *this;
}

Matrix &Matrix::operator-=(const Matrix& a) {
    matrix = (*this - a).getMatrix();
    return *this;
}

Matrix &Matrix::operator*=(const Matrix& a) {
    matrix = (*this * a).getMatrix();
    return *this;
}

Matrix &Matrix::operator*=(double a) {
    matrix = (*this * a).getMatrix();
    return *this;
}

Matrix &Matrix::operator/=(const Matrix& a) {
    matrix = (*this / a).getMatrix();
    return *this;
}

Matrix &Matrix::operator/=(double a) {
    matrix = (*this / a).getMatrix();
    return *this;
}

mVector Matrix::getMatrix() const {
    return matrix;
}

Matrix operator+(const Matrix& a, const Matrix& b) {
    mVector newMatrixVector(a.getRows(), vDouble(a.getColumns(), 0));

    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getColumns(); ++j) {
            newMatrixVector[i][j] = a.getMatrix()[i][j] + b.getMatrix()[i][j];
        }
    }
    return Matrix(a.getRows(), a.getColumns(), newMatrixVector);
}

Matrix operator-(const Matrix& a, const Matrix& b) {
    mVector newMatrixVector(a.getRows(), vDouble(a.getColumns(), 0));

    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getColumns(); ++j) {
            newMatrixVector[i][j] = a.getMatrix()[i][j] - b.getMatrix()[i][j];
        }
    }
    return Matrix(a.getRows(), a.getColumns(), newMatrixVector);
}

Matrix operator*(const Matrix& a, const Matrix& b) {
    mVector newMatrixVector(a.getRows(), vDouble(a.getColumns(), 0));

    for (int i = 0; i < a.getRows(); i++) {
        for (int j = 0; j < b.getColumns(); j++) {
            for (int k = 0; k < a.getColumns(); k++) {
                newMatrixVector[i][j] += a.getMatrix()[i][k] * b.getMatrix()[k][j];
            }
        }
    }
    return Matrix(a.getRows(), b.getColumns(), newMatrixVector);
}

Matrix operator*(const Matrix& a, double b) {
    mVector newMatrixVector(a.getRows(), vDouble(a.getColumns(), 0));

    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getColumns(); ++j) {
            newMatrixVector[i][j] = a.getMatrix()[i][j] * b;
        }
    }
    return Matrix(a.getRows(), a.getColumns(), newMatrixVector);
}

Matrix operator/(const Matrix& a, const Matrix& b) {
    return a * b.reversed();
}

Matrix operator/(const Matrix& a, double b) {
    return a * (1 / b);
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.getRows() != b.getRows() || a.getColumns() != b.getColumns())
        return false;

    for (int i = 0; i < min(a.getRows(), b.getRows()); ++i) {
        for (int j = 0; j < min(a.getColumns(), b.getColumns()); ++j) {
            if (a.getMatrix()[i][j] != b.getMatrix()[i][j])
                return false;
        }
    }
    return true;
}

bool operator!=(const Matrix& a, const Matrix& b) {
    return !(a == b);
}

