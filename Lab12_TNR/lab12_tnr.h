#ifndef LAB12_TNR_H
#define LAB12_TNR_H

#include <QMainWindow>
#include "mymatrix_tnr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab12_TNR; }
QT_END_NAMESPACE

class Lab12_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab12_TNR(QWidget *parent = nullptr);
    ~Lab12_TNR();

private slots:
    void on_matr1SetBtn_tnr_pressed();

    void on_matr1ResizeBtn_tnr_pressed();

    void on_matr1RandomBtn_tnr_pressed();

    void on_matr1ArMean_tnr_pressed();

    void on_matr2SetBtn_tnr_pressed();

    void on_matr2ResizeBtn_tnr_pressed();

    void on_matr2RandomBtn_tnr_pressed();

    void on_equalsBtn_tnr_pressed();

    void on_matr1GetValBtn_tnr_pressed();

    void on_matr2GetValBtn_tnr_pressed();

    void on_matr2DetBtn_tnr_pressed();

private:
    Ui::Lab12_TNR *ui;
    MyMatrix_TNR * matrix1 = new MyMatrix_TNR(4);
    MyMatrix_TNR * matrix2 = new MyMatrix_TNR(4);
    MyMatrix_TNR * matrix3 = new MyMatrix_TNR(4);
};
#endif // LAB12_TNR_H
