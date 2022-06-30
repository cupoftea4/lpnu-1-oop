#include "lab12_tnr.h"
#include "ui_lab12_tnr.h"

Lab12_TNR::Lab12_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab12_TNR)
{
    ui->setupUi(this);
    ui->errorMsg_tnr->setStyleSheet("QLabel { color : red; }");
    ui->errorMsg_tnr->clear();
    *(ui->grid1) << *matrix1;
    *(ui->grid2) << *matrix2;
}

Lab12_TNR::~Lab12_TNR()
{
    delete matrix1;
    delete matrix2;
    delete matrix3;
    delete ui;
}


void Lab12_TNR::on_matr1SetBtn_tnr_pressed()
{
    try {
        *(ui->grid1) >> *matrix1;

        try {
            ui->errorMsg_tnr->clear();
        }  catch (...) {
            std::cin.ignore(5, '\n');


        }
    }  catch (const std::runtime_error& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}


void Lab12_TNR::on_matr1ResizeBtn_tnr_pressed()
{
    long i = ui->matr1I_tnr->value(), j = ui->matr1J_tnr->value();
    try {
        matrix1->SetSize(i, j);
        ui->errorMsg_tnr->clear();
    } catch (const std::invalid_argument& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
    *(ui->grid1) << *matrix1;
}


void Lab12_TNR::on_matr1RandomBtn_tnr_pressed()
{
    matrix1->FillRandom();
    *(ui->grid1) << *matrix1;
}


void Lab12_TNR::on_matr1ArMean_tnr_pressed()
{
    try {
        double det = matrix1->Determinant();
        ui->matr1Det_tnr->setText(QString::number(det));
        ui->errorMsg_tnr->clear();
    }  catch (const std::runtime_error& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}


void Lab12_TNR::on_matr2SetBtn_tnr_pressed()
{
    try {
        *(ui->grid2) >> *matrix2;
        ui->errorMsg_tnr->clear();
    }  catch (const std::runtime_error& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}


void Lab12_TNR::on_matr2ResizeBtn_tnr_pressed()
{
    long i = ui->matr2I_tnr->value(), j = ui->matr2J_tnr->value();
    try {
        matrix2->SetSize(i, j);
        ui->errorMsg_tnr->clear();
    } catch (const std::invalid_argument& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
    *(ui->grid2) << *matrix2;
}


void Lab12_TNR::on_matr2RandomBtn_tnr_pressed()
{
    matrix2->FillRandom();
    *(ui->grid2) << *matrix2;
}


void Lab12_TNR::on_equalsBtn_tnr_pressed()
{
    int index = ui->operation_tnr->currentIndex();
    ui->errorMsg_tnr->clear();
    switch (index) {
        case 0:
            try {
                matrix3 = *matrix1 * *matrix2;
            }  catch (const std::runtime_error& error) {
                ui->errorMsg_tnr->setText(error.what());
            }
            break;
        case 1:
            matrix3 = *matrix1 - *matrix2;
            break;
        case 2:
            matrix3 = *matrix1 + *matrix2;
            break;
        case 3:
            try {
                matrix3 = matrix1->Inverse();
            }  catch (const std::runtime_error& error) {
                ui->errorMsg_tnr->setText(error.what());
            }
    }
    *(ui->grid3) << *matrix3;
}


void Lab12_TNR::on_matr1GetValBtn_tnr_pressed()
{
    long i = ui->matr1I_tnr->value(), j = ui->matr1J_tnr->value();
    try {
        ui->matr1Val_tnr->setText(QString::number(matrix1->At(--i, --j)));
        ui->errorMsg_tnr->clear();
    }  catch (const std::out_of_range& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}


void Lab12_TNR::on_matr2GetValBtn_tnr_pressed()
{
    long i = ui->matr2I_tnr->value(), j = ui->matr2J_tnr->value();
    try {
        ui->matr1Val_tnr->setText(QString::number(matrix2->At(--i, --j)));
        ui->errorMsg_tnr->clear();
    }  catch (const std::out_of_range& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}


void Lab12_TNR::on_matr2DetBtn_tnr_pressed()
{
    try {
        double det = matrix2->Determinant();
        ui->matr2Det_tnr->setText(QString::number(det));
        ui->errorMsg_tnr->clear();
    }  catch (const std::runtime_error& error) {
        ui->errorMsg_tnr->setText(error.what());
    }
}



