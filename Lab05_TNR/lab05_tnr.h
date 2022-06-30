#ifndef LAB05_H
#define LAB05_H

#include <QMainWindow>
#include "polynom_tnr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab05; }
QT_END_NAMESPACE

class Lab05 : public QMainWindow
{
    Q_OBJECT

public:
    Lab05(QWidget *parent = nullptr);
    ~Lab05();

private slots:
    void on_setPolynom1Btn_pressed();
    void on_setPolynom2Btn_pressed();
    void on_derivativeBtn_pressed();
    void on_integralBtn_pressed();
    void on_addBtn_pressed();
    void on_subtractBtn_pressed();
    void on_calculateBtn_pressed();

private:
    Polynom * polynom1 = new Polynom(1, 0, 0);
    Polynom * polynom2 = new Polynom(1, 0, 0);
    Ui::Lab05 *ui;
};
#endif // LAB0_H
