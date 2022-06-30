#ifndef LAB06_TNR_H
#define LAB06_TNR_H

#include <QMainWindow>
#include "polynom_tnr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab06_TNR; }
QT_END_NAMESPACE

class Lab06_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab06_TNR(QWidget *parent = nullptr);
    ~Lab06_TNR();

private slots:
    void on_setPolynom1Btn_pressed();

    void on_setPolynom2Btn_pressed();

    void on_derivativeBtn_pressed();

    void on_integralBtn_pressed();

    void on_addBtn_pressed();

    void on_subtractBtn_pressed();

    void on_calculateBtn_pressed();

    void on_inverseBtn_pressed();

    void on_multBy_pressed();

    void on_areEqualBtn_pressed();

    void on_polynomsCountBtn_pressed();

private:
    Polynom_TNR * polynom1 = new Polynom_TNR(1, 0, 0);
    Polynom_TNR * polynom2 = new Polynom_TNR(1, 0, 0);
    Ui::Lab06_TNR *ui;
};
#endif // LAB05_TNR_H
