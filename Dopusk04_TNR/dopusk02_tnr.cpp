#include "dopusk02_tnr.h"
#include "ui_dopusk02_tnr.h"

Dopusk02_TNR::Dopusk02_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dopusk02_TNR)
{
    ui->setupUi(this);

}

void Dopusk02_TNR::on_pushButton_pressed()
{
    QGridLayout * grid = ui->gridLayout;
    int start = ui->valueSpinBox1->text().toInt();
    int step =  ui->valueSpinBox2->text().toInt();
    int sizeX = ui->sizeSpinBox1->text().toInt();
    int sizeY = ui->sizeSpinBox2->text().toInt();
    matrixSize.setHeight(sizeY);
    matrixSize.setWidth(sizeX);
    start-=step;
    for (int x = 0; x < sizeX; x++ ) {
        for (int y = 0; y < sizeY; y++ ) {
            QPushButton * button = new QPushButton;
            button->setFixedSize(180/sizeX, 180/sizeY);
            button->setText(QString::number(start+=step));
            grid->addWidget(button, x+1, y+1);
            buttons[x][y] = button;
        }
    }
}

void Dopusk02_TNR::on_getBtn_pressed()
{
    int x = ui->iEdit->text().toInt();
    int y = ui->jEdit->text().toInt();
    QString value = buttons[x-1][y-1]->text();
    ui->valueEdit->setText(value);
}

void Dopusk02_TNR::on_setBtn_pressed()
{
    int x = ui->iEdit->text().toInt();
    int y = ui->jEdit->text().toInt();
    QString value = ui->valueEdit->text();
    buttons[x-1][y-1]->setText(value);
}

Dopusk02_TNR::~Dopusk02_TNR()
{
    delete ui;
}

void Dopusk02_TNR::on_closeBtn_pressed()
{
    close();
}

void Dopusk02_TNR::on_pushButton_2_pressed()
{
    int sum = 0;
    if (matrixSize.height() != matrixSize.width()) {
        ui->valueEdit->setText("not square matrix");
        return;
    }
    int size = matrixSize.height();
    for (int i = 0; i < size; i++) {
//        qDebug() << buttons[size-i-1][i]->text();
        sum+=buttons[size-i-1][i]->text().toInt();
    }
    ui->valueEdit->setText(QString::number(sum));
}


void Dopusk02_TNR::on_rotateBtn_pressed()
{
    if (matrixSize.height() != matrixSize.width()) {
        ui->valueEdit->setText("not square matrix");
        return;
    }
    int size = matrixSize.height();
    for (int i = 0; i < size / 2; i++) {
        for (int j = i; j < size - i - 1; j++) {
            QString temp = buttons[i][j]->text();
            buttons[i][j]->setText(buttons[size - 1 - j][i]->text());
            buttons[size - 1 - j][i]->setText(buttons[size - 1 - i][size - 1 - j]->text());
            buttons[size - 1 - i][size - 1 - j]->setText(buttons[j][size - 1 - i]->text());
            buttons[j][size - 1 - i]->setText(temp);
        }
    }

}


void Dopusk02_TNR::on_rotate1Btn_pressed()
{
    if (matrixSize.height() != matrixSize.width()) {
        ui->valueEdit->setText("not square matrix");
        return;
    }
    QString temp;
    int size = matrixSize.height();
    for (int i = 0; i < size / 2; i++) {
        for (int j = i; j < size - i - 1; j++) {
            temp = buttons[i][j]->text();
            buttons[i][j]->setText(buttons[j][size - 1 - i]->text());
            buttons[j][size - 1 - i]->setText(buttons[size - 1 - i][size - 1 - j]->text());
            buttons[size - 1 - i][size - 1 - j]->setText(buttons[size - 1 - j][i]->text());
            buttons[size - 1 - j][i]->setText(temp);
        }
    }
}

