#include "lab06_tnr.h"
#include "ui_lab06_tnr.h"

Lab06_TNR::Lab06_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab06_TNR)
{
    ui->setupUi(this);
}

Lab06_TNR::~Lab06_TNR()
{
    delete polynom1;
    delete polynom2;
    delete ++ui;
}

void Lab06_TNR::on_setPolynom1Btn_pressed()
{
    double a = ui->aInput1_tnr->text().toDouble();
    if (a == 0) a = 1;
    double b = ui->bInput1_tnr->text().toDouble();
    double c = ui->cInput1_tnr->text().toDouble();
    polynom1->SetPolynom(a, b, c);
    ui->polynom1->setText(polynom1->GetQPolynom());
    double x1, x2;
    if (!polynom1->Solve(x1, x2)) {
        ui->x1->setText("D < 0");
        return;
    }
    ui->x1->setText(QString::number(x1));
    ui->x2->setText(QString::number(x2));
}


void Lab06_TNR::on_setPolynom2Btn_pressed()
{
    double a = ui->aInput2_tnr->text().toDouble();
    if (a == 0) a = 1;
    double b = ui->bInput2_tnr->text().toDouble();
    double c = ui->cInput2_tnr->text().toDouble();
    polynom2->SetPolynom(a, b, c);
    ui->polynom2->setText(polynom2->GetQPolynom());
}


void Lab06_TNR::on_derivativeBtn_pressed()
{
    double x = ui->derivativeX_tnr->text().toDouble();
    ui->derivativeRes_tnr->setText(QString::number(polynom1->Derivative(x)));
}


void Lab06_TNR::on_integralBtn_pressed()
{
    double start = ui->intervalStart_tnr->text().toDouble();
    double end = ui->intervalEnd_tnr->text().toDouble();
    ui->integralRes_tnr->setText(QString::number(polynom1->DefiniteIntegral(start, end)));
}


void Lab06_TNR::on_addBtn_pressed()
{
    Polynom_TNR * res = *polynom1 + *polynom2;
    res = polynom1->operator+(*polynom2);
//    res = operator+(*polynom1, *polynom2);
    QString (Polynom_TNR:: *f)();
    f = &Polynom_TNR::GetQPolynom;
    (polynom1->*f)();
    ui->sumRes_tnr->setText(res->GetQPolynom());
}


void Lab06_TNR::on_subtractBtn_pressed()
{
    Polynom_TNR * res = *polynom1 - *polynom2;
    ui->difRes_tnr->setText(res->GetQPolynom());
}


void Lab06_TNR::on_calculateBtn_pressed()
{
    double x = ui->calculateX_tnr->text().toDouble();
    ui->calcRes_tnr->setText(QString::number(polynom1->Calculate(x)));
}


void Lab06_TNR::on_inverseBtn_pressed()
{
    ui->polynom1->setText(polynom1->operator!()->GetQPolynom());
}


void Lab06_TNR::on_multBy_pressed()
{
    Multiply(*polynom1, 2);
    ui->polynom1->setText(polynom1->GetQPolynom());
}


void Lab06_TNR::on_areEqualBtn_pressed()
{
    if (operator==(*polynom1, *polynom2)) {
        ui->areEqual_tnr->setText("They are equal");
    } else {
        ui->areEqual_tnr->setText("They are NOT equal");
    }
}


void Lab06_TNR::on_polynomsCountBtn_pressed()
{
    ui->polynomsCount_tnr->setText(QString::number(Polynom_TNR::GetPolynomsCount()));
}

