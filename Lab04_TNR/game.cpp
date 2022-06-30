#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    QGridLayout &layout = *ui->gridLayout;
    for (int x = 0; x < 5; x++ ) {
        for (int y = 0; y < 5; y++ ) {
            QPushButton &button = *new QPushButton;
            QObject::connect(&button, SIGNAL(released()), this, SLOT(SwapElements()));
            RubikRaceElement &rubikButton = *new RubikRaceElement(button, x+1, y+1);
            rubikButton.RubikRaceElement::getName();
            int * pR = new int;
            button.setFixedSize(60, 60);
            layout.addWidget(&button, x+1, y+1);
            buttons[x][y] = &rubikButton;
        }
    }

}

void Game::SwapElements() {
    for (int x = 0; x < 5; x++ ) {
        for (int y = 0; y < 5; y++ ) {
            qDebug() << buttons[x][y]->getName();
        }
    }
}


Game::~Game()
{
    delete ui;
}

