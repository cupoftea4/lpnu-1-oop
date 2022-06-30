#ifndef MATRIX_TNR_H
#define MATRIX_TNR_H

#include <iostream>
#include <cmath>
#include <QGridLayout>
#include <QLineEdit>
#include <QLayoutItem>
#include <QTextEdit>
#include <stdlib.h>
#include <algorithm>

class Matrix_TNR
{
public:
    Matrix_TNR();
    Matrix_TNR(int n, int m);
    Matrix_TNR(Matrix_TNR * matr);
    ~Matrix_TNR();

    double FindMax();
    double FindArithmeticMean();
    void SortRowAcsending(int index);
    void SortColumnDescending(int index);
    void FillRandom();
    Matrix_TNR * Pow(int n);

    void SetSize(int rows, int cols);
    void SetAt (int i, int j, double num) { if (i >= 0 && i < rows && j >= 0 && j < cols) matrix[i][j] = num; }
    double* &operator[](const int &index) const;

    Matrix_TNR * operator+(const Matrix_TNR &matr);
    Matrix_TNR * operator-(const Matrix_TNR &matr);
    Matrix_TNR * operator*(const Matrix_TNR &matr);
    Matrix_TNR * operator=(Matrix_TNR  * matr);
    Matrix_TNR * operator*(const double coeff);

    friend void operator<<(QGridLayout &grid, const Matrix_TNR& polynom);
    friend void operator<<(QTextEdit &textedit, const Matrix_TNR& polynom);
    friend void operator>>(const QGridLayout &grid, Matrix_TNR& polynom);


private:
    void AllocMatrix();
    enum SortWay { Descending, Ascending };
    int Min(const double * array, int start, int n);
    int Max(const double * array, int start, int n);
    void Swap(double * array, int n, int m);
    void SelectionSort(double * array, int n, SortWay way);
    double At (int i, int j) const { return matrix[i][j];  }
    double ** matrix;
    int rows = 0;
    int cols = 0;
};

#endif // MATRIX_TNR_H
