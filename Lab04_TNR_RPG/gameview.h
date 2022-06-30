#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFontDatabase>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPoint>
#include "healpotionspawner.h"
#include "orcspawner.h"
#include "creature.h"
#include "textitem.h"
#include "arrow.h"
#include "hero.h"
#include "labelsmanager.h"
#include "toastmessage.h"
#include "message.h"

class GameView : public QGraphicsView
{
public:
    GameView();
    QGraphicsScene * setUpScene();
    void setViewSize(int w, int h) {viewW = w; viewH = h;}
    int viewW;
    int viewH;
private slots:
    void loadNextLevel();
    void closeGame();

private:
    void ResetGame();
    bool UpdateLevel(int toAdd);
    void restartWindow();
    int level = 1;
    bool heroCreated = false;
    Hero * hero;
};

#endif // GAMEVIEW_H
