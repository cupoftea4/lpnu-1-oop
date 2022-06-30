#include "game.h"

#include <QApplication>

static int n = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w;
    w.show();
    return a.exec();
}
