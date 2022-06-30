#include "game.h"
#include "ui_game.h"
#include "hero.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <myrect.h>

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    QPixmap pixmap("cat.jpg");
//    qDebug()<<"File exists -"<<QFileInfo("cat.jpg").exists()<<" "<<QFileInfo("cat.jpg").absoluteFilePath();
//    ui->label->setPixmap(pixmap);
    setWindowTitle("Бандерогусь");

//    Hero * character = new Hero();

//    qDebug() << character->getGold();
    //    delete(character);

}

Game::~Game()
{
    delete ui;
}

