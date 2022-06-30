#ifndef GAME_LAB4_H
#define GAME_LAB4_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Game_Lab4; }
QT_END_NAMESPACE

class Game_Lab4 : public QMainWindow
{
    Q_OBJECT

public:
    Game_Lab4(QWidget *parent = nullptr);
    ~Game_Lab4();
private slots:
    void BtnPressed();
private: 
    bool CheckWin();
    bool isDraw();
    void Restart(QString winner);
    QString move = "x";
    Ui::Game_Lab4 *ui;
};
#endif // GAME_LAB4_H
