#ifndef MYMATRIX_TNR_H
#define MYMATRIX_TNR_H

#include <iostream>
#include <cmath>
#include <QGridLayout>
#include <QLineEdit>
#include <QLayoutItem>
#include <QTextEdit>
#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <QLabel>
#include <QMessageBox>
#include <fstream>
#include <QDateTime>

class MyMatrix_TNR
{
public:
    MyMatrix_TNR();
    MyMatrix_TNR(long n, long m);
    MyMatrix_TNR(long size);
    MyMatrix_TNR(MyMatrix_TNR &matr);
    ~MyMatrix_TNR();

    double FindMax();
    double FindArithmeticMean();
    void FillRandom(int max = 20);
    MyMatrix_TNR *Pow(int n);
    MyMatrix_TNR *Inverse();
    MyMatrix_TNR *Transpose();
    double Determinant();

    void SetSize(long rows, long cols);
    void SetAt (long i, long j, double num);
    double At(long i, long j);
    size_t GetRows() const;
    size_t GetCols() const;
    void Print(QString str = "");
    void Clear(double num = 0);
    double Round(double num, int n) const;

    MyMatrix_TNR * operator+(MyMatrix_TNR &matr);
    MyMatrix_TNR * operator-(MyMatrix_TNR &matr);
    MyMatrix_TNR * operator*(MyMatrix_TNR &matr);
    MyMatrix_TNR * operator=(MyMatrix_TNR  * matr);
    MyMatrix_TNR * operator*(const double coeff);

    friend void operator<<(QGridLayout &grid, const MyMatrix_TNR& polynom);
    friend void operator<<(QTextEdit &textedit, const MyMatrix_TNR& polynom);
    friend void operator>>(const QGridLayout &grid, MyMatrix_TNR& polynom);


private:
    enum Type {Error, Warning, Success};
    void Log(std::string str, Type type = Success);
    size_t Size();
    void SubMatrix(MyMatrix_TNR * matr, size_t p, std::vector<size_t> skips);
    double DeterminantRecursive(MyMatrix_TNR * temp, size_t size, std::vector<size_t> skips);
    double Minor(size_t i, size_t j);
    void AllocMatrix();
    void Free();
    size_t min(size_t a, size_t b);
    double ** matrix = nullptr;
    size_t rows = 0;
    size_t cols = 0;
    const size_t MaxSize = LONG_MAX;
    QLabel * label = nullptr;
    std::ofstream outdata;
};

#endif // MYMATRIX_TNR_H
