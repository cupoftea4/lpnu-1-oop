#include "game_lab4.h"
#include "ui_game_lab4.h"

Game_Lab4::Game_Lab4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game_Lab4)
{
    ui->setupUi(this);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            QPushButton * btn = this->findChild<QPushButton*>("Btn_" + QString::number(i) + "_" + QString::number(j));
            connect(btn, SIGNAL(pressed()), this, SLOT(BtnPressed()));
        }
    }
}

Game_Lab4::~Game_Lab4()
{
    delete ui;
}

void Game_Lab4::BtnPressed()
{
    QPushButton * btn = (QPushButton*)sender();
    btn->setText(move);
    if (CheckWin()) {
        QMessageBox msg;
        msg.setText(move + " wins!");
        msg.exec();
        Restart(move);
        return;
    }
    if (isDraw()) {
        QMessageBox msg;
        msg.setText("Нічия!");
        msg.exec();
        Restart(move);
        return;
    }
    if (move == "x") {
        move = "o";
    } else {
        move = "x";
    }
    ui->label->setText("Ходить: " + move);

}

bool Game_Lab4::CheckWin()
{
    QPushButton * buttons[3][3];
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            QPushButton * btn = this->findChild<QPushButton*>("Btn_" + QString::number(i) + "_" + QString::number(j));
            buttons[i-1][j-1] = btn;
        }
    }

    QString temp; int symbolsCount;
    for (int i = 0; i < 3; i++) {
        // провірка рядка
        temp = buttons[i][0]->text(); symbolsCount = 1;
        for (int j = 1; j < 3; j++) {
            if (temp == "") break;
            if (temp ==  buttons[i][j]->text()) symbolsCount++;
        }
        if (symbolsCount == 3) return true;

        // провірка стовпчика
        temp = buttons[0][i]->text(); symbolsCount = 1;
        if (temp == "") continue;
        for (int j = 1; j < 3; j++) {
            if (temp ==  buttons[j][i]->text()) symbolsCount++;
        }
        if (symbolsCount == 3) return true;
    }

    // головна діагональ
    temp = buttons[0][0]->text(); symbolsCount = 1;
    for (int i = 1; i < 3; i++) {
        if (temp == "") break;
        if (temp ==  buttons[i][i]->text()) symbolsCount++;
    }
    if (symbolsCount == 3) return true;

    // побічна діагональ
    temp = buttons[0][2]->text(); symbolsCount = 1;
    for (int i = 1; i < 3; i++) {
        if (temp == "") break;
        if (temp ==  buttons[i][2-i]->text()) symbolsCount++;
    }
    if (symbolsCount == 3) return true;

    return false;
}

bool Game_Lab4::isDraw()
{
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            QPushButton * btn = this->findChild<QPushButton*>("Btn_" + QString::number(i) + "_" + QString::number(j));
            if (btn->text() == "") return false;
        }
    }
    return true;
}

void Game_Lab4::Restart(QString winner)
{
    move = winner;
    ui->label->setText("Ходить: " + move);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            QPushButton * btn = this->findChild<QPushButton*>("Btn_" + QString::number(i) + "_" + QString::number(j));
            btn->setText("");
        }
    }
}

