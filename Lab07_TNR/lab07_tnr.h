#ifndef LAB07_TNR_H
#define LAB07_TNR_H

#include <QMainWindow>
#include <QGridLayout>
#include <matrix_tnr.h>
#include <QCloseEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Lab07_TNR; }
QT_END_NAMESPACE

class Lab07_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab07_TNR(QWidget *parent = nullptr);
    ~Lab07_TNR();

private slots:
    void on_matr1SetBtn_tnr_pressed();

    void on_matr2SetBtn_tnr_pressed();

    void on_equalsBtn_tnr_pressed();

    void on_matr1ResizeBtn_tnr_pressed();

    void on_matr2ResizeBtn_tnr_pressed();

    void on_sortRowBtn_tnr_pressed();

    void on_sortColBtn_tnr_pressed();

    void on_matr1RandomBtn_tnr_pressed();

    void on_matr2RandomBtn_tnr_pressed();

    void on_matr3RandomBtn_tnr_pressed();

    void on_outputBtn_tnr_pressed();

    void on_matr1ArMean_tnr_pressed();

    void on_matr1Max_tnr_pressed();

    void on_getBtn_tnr_pressed();

private:
    Ui::Lab07_TNR *ui;
    Matrix_TNR * matrix1;
    Matrix_TNR * matrix2;
    Matrix_TNR * matrix3;
    const int initialSize = 3;
};
#endif // LAB07_TNR_H
