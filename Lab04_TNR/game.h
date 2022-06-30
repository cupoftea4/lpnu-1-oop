#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include "rubikraceelement.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    RubikRaceElement * buttons[5][5];

public slots:
    void SwapElements();

};
#endif // GAME_H
