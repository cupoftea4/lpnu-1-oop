#ifndef LAB10_TNR_H
#define LAB10_TNR_H

#include <QMainWindow>
#include "string_tnr.h"
#include "array_tnr.h"
#define SIZE 10
#define MAX_COEFF 20

QT_BEGIN_NAMESPACE
namespace Ui { class Lab10_TNR; }
QT_END_NAMESPACE

class Lab10_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab10_TNR(QWidget *parent = nullptr);
    ~Lab10_TNR();

private slots:

    void on_addToEndBtn_tnr_pressed();

    void on_setAtBtn_tnr_clicked();

    void on_randBtn_tnr_clicked();

    void on_sortABtn_tnr_pressed();

    void on_sortDBtn_tnr_pressed();

    void on_minBtn_tnr_pressed();

    void on_fillBtn_tnr_pressed();

    void on_clearBtn_tnr_pressed();

    void on_comboBox_currentIndexChanged(int index);

private:
    void UpdateList();
    Ui::Lab10_TNR *ui;
    Array_TNR<String_TNR> * strArr = new Array_TNR<String_TNR>();
    Array_TNR<Polynom_TNR> * polArr = new Array_TNR<Polynom_TNR>();
    const QString randStrings[SIZE] = {
        "Lorem ipsum dolor sit amet",
        "consectetur adipiscing elit",
        "Duis finibus malesuada ante",
        "vel porta lacus malesuada a",
        "Quisque ac tellus nec diam,",
        "ultricies tempus id vel magna,",
        "Aliquam egestas eu odio ut efficitur",
        "Duis lectus elit",
        "mollis nec finibus eget,",
        "feugiat id ante."
    };
    enum Modes {String_TNRs, Polynom_TNRs};
    Modes mode = String_TNRs;

};
#endif // LAB10_TNR_H
