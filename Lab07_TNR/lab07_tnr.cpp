#include "lab07_tnr.h"
#include "ui_lab07_tnr.h"

Lab07_TNR::Lab07_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab07_TNR)
{
    ui->setupUi(this);

    matrix1 = new Matrix_TNR(initialSize, initialSize);
    *(ui->grid1) << *matrix1;
    matrix2 = new Matrix_TNR(initialSize, initialSize);
    *(ui->grid2) << *matrix2;
    matrix3 = new Matrix_TNR(initialSize, initialSize);
    *(ui->grid3) << *matrix3;
}

Lab07_TNR::~Lab07_TNR()
{
    delete matrix1;
    delete matrix2;
    delete matrix3;
    delete ui;
}


void Lab07_TNR::on_matr1SetBtn_tnr_pressed()
{
    *(ui->grid1) >> *matrix1;
}


void Lab07_TNR::on_matr2SetBtn_tnr_pressed()
{
    *(ui->grid2) >> *matrix2;
}


void Lab07_TNR::on_equalsBtn_tnr_pressed()
{
    int index = ui->operation_tnr->currentIndex();
    double coeff = ui->coeff_tnr->text().toDouble();
    switch (index) {
        case 0:
            if (*matrix1 * *matrix2 == nullptr) {
                QMessageBox msg;
                msg.setText("Wrong sizes. Rows count of the first matrix must equal columns count of the second one.");
                msg.exec();
                return;
            }
            matrix3 = *matrix1 * *matrix2;
            break;
        case 1:
            matrix3 = *matrix1 - *matrix2;
            break;
        case 2:
            matrix3 = *matrix1 + *matrix2;
            break;
        case 3:
            matrix3 = *matrix1 * coeff;
            break;
        case 4:
            matrix3 = matrix1->Pow(coeff);
    }
    *(ui->grid3) << *matrix3;

}


void Lab07_TNR::on_matr1ResizeBtn_tnr_pressed()
{
    int i = ui->matr1I_tnr->text().toInt();
    int j = ui->matr1J_tnr->text().toInt();
    matrix1->SetSize(i, j);
    *(ui->grid1) << *matrix1;
}


void Lab07_TNR::on_matr2ResizeBtn_tnr_pressed()
{
    int i = ui->matr2I_tnr->text().toInt();
    int j = ui->matr2J_tnr->text().toInt();
    matrix2->SetSize(i, j);
    *(ui->grid2) << *matrix2;
}


void Lab07_TNR::on_sortRowBtn_tnr_pressed()
{
    int row = ui->row_tnr->text().toInt();
    matrix3->SortRowAcsending(row);
    *(ui->grid3) << *matrix3;
}


void Lab07_TNR::on_sortColBtn_tnr_pressed()
{
    int col = ui->col_tnr->text().toInt();
    matrix3->SortColumnDescending(col);
    *(ui->grid3) << *matrix3;
}


void Lab07_TNR::on_matr1RandomBtn_tnr_pressed()
{
   matrix1->FillRandom();
   *(ui->grid1) << *matrix1;
}


void Lab07_TNR::on_matr2RandomBtn_tnr_pressed()
{
    matrix2->FillRandom();
    *(ui->grid2) << *matrix2;
}


void Lab07_TNR::on_matr3RandomBtn_tnr_pressed()
{
    matrix3->FillRandom();
    *(ui->grid3) << *matrix3;
}


void Lab07_TNR::on_outputBtn_tnr_pressed()
{
    *(ui->textEdit) << *matrix1;
}



void Lab07_TNR::on_matr1ArMean_tnr_pressed()
{
    double res = matrix1->FindArithmeticMean();
    ui->resulr_tnr->setText(QString::number(res));
}


void Lab07_TNR::on_matr1Max_tnr_pressed()
{
    double res = matrix1->FindMax();
    ui->resulr_tnr->setText(QString::number(res));
}


void Lab07_TNR::on_getBtn_tnr_pressed()
{
    int i = ui->matr1I_tnr->text().toInt();
    int j = ui->matr1J_tnr->text().toInt();
    ui->get_tnr->setText(QString::number(*matrix1[i][j]));
}

