#include "dopusk02_tnr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dopusk02_TNR w;
    w.show();
    return a.exec();
}
