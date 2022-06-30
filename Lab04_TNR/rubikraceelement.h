#ifndef RUBIKRACEELEMENT_H
#define RUBIKRACEELEMENT_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

class RubikRaceElement
{

private:
    QString name;
    QPushButton *button;
    bool isEmpty = false;
    int x;
    int y;

public:
    RubikRaceElement(QPushButton &button, int x, int y);
    QString getName() {
      return name;
    }

//signals:
////    void SwapElements();
//    void ElementReleased();

};

#endif // RUBIKRACEELEMENT_H
