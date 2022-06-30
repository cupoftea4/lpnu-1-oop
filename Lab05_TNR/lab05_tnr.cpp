#include "lab05_tnr.h"
#include "ui_lab05_tnr.h"

Lab05::Lab05(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab05)
{
    ui->setupUi(this);
}

Lab05::~Lab05()
{
    delete polynom1;
    delete polynom2;
    delete ++ui;
}

void Lab05::on_setPolynom1Btn_pressed()
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


void Lab05::on_setPolynom2Btn_pressed()
{
    double a = ui->aInput2_tnr->text().toDouble();
    if (a == 0) a = 1;
    double b = ui->bInput2_tnr->text().toDouble();
    double c = ui->cInput2_tnr->text().toDouble();
    polynom2->SetPolynom(a, b, c);
    ui->polynom2->setText(polynom2->GetQPolynom());
}


void Lab05::on_derivativeBtn_pressed()
{
    double x = ui->derivativeX_tnr->text().toDouble();
    ui->derivativeRes_tnr->setText(QString::number(polynom1->Derivative(x)));
}


void Lab05::on_integralBtn_pressed()
{
    double start = ui->intervalStart_tnr->text().toDouble();
    double end = ui->intervalEnd_tnr->text().toDouble();
    ui->integralRes_tnr->setText(QString::number(polynom1->DefiniteIntegral(start, end)));
}


void Lab05::on_addBtn_pressed()
{
    Polynom * res = *polynom1 + *polynom2;
    ui->sumRes_tnr->setText(res->GetQPolynom());
}


void Lab05::on_subtractBtn_pressed()
{
    Polynom * res = *polynom1 - *polynom2;
    ui->difRes_tnr->setText(res->GetQPolynom());
}


void Lab05::on_calculateBtn_pressed()
{
    double x = ui->calculateX_tnr->text().toDouble();
    ui->calcRes_tnr->setText(QString::number(polynom1->Calculate(x)));
}


