#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QTimer>
#include <QFileInfo>

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
};
#endif // GAME_H
