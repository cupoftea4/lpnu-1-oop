#include "game.h"

#include <QGraphicsScene>
#include "gameview.h"
#include "message.h"

/*
 To do:
    - scene size
    - arrow range 300px
    - split setUpScene into methods
    - naming standards
*/

QGraphicsScene * setUpScene(int width, int height);
void restartWindow();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash= new QSplashScreen( QPixmap("loadingScreen.jpg"), Qt::WindowStaysOnTopHint);
    splash->show();
    QFontDatabase::addApplicationFont("amoreiza-regular.ttf");

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    qDebug() << width;


    GameView * view = new GameView();
    view->setViewSize(width, height);
    view->setUpScene();

    QTimer::singleShot(1000, splash, SLOT(close()));
    QTimer::singleShot(1000, view, SLOT(show()));
    return a.exec();
}

void restartWindow() {
    Message restartMessageBox;
    restartMessageBox.show();
}


