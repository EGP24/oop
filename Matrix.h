#pragma once
#include <vector>

#define vDouble std::vector<double>
#define mVector std::vector<vDouble>


class Matrix
{
    private:
        mVector matrix;
        int rows{};
        int columns{};
    public:
        Matrix();
        explicit Matrix(int rows, int columns, const mVector& matrix);
        ~Matrix();
        void print() const;

        bool isSquare() const;
        bool isDiagonal() const;
        bool isZeroMatrix() const;
        bool isSingleMatix() const;
        bool isSymmetrical() const;
        bool isTopTriangle() const;
        bool isBotTriangle() const;

        Matrix transposed() const;
        Matrix power(int n) const;
        Matrix reversed() const;

        double determinant() const;
        vDouble norm() const;

        Matrix getMatrixWithoutRowAndCol(int row, int col) const;
        std::vector<std::vector<double>> getMatrix() const;
        int getRows() const;
        int getColumns() const;

        Matrix& operator+=(const Matrix& a);
        Matrix& operator-=(const Matrix& a);
        Matrix& operator*=(const Matrix& a);
        Matrix& operator/=(const Matrix& a);
        Matrix& operator*=(double a);
        Matrix& operator/=(double a);
};


Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);
Matrix operator/(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, double b);
Matrix operator/(const Matrix& a, double b);

bool operator==(const Matrix& a, const Matrix& b);
bool operator!=(const Matrix& a, const Matrix& b);