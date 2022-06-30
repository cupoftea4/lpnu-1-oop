#include "rubikraceelement.h"

RubikRaceElement::RubikRaceElement(QPushButton &button, int x, int y) {
    this->x = x;
    this->y = y;
    this->button = &button;
    this->name = QString::number(x) + " " + QString::number(y);
//    QObject::connect(&button, &QPushButton::clicked, &Game::SwapElements);
    if(x == 5 && y == 5) {
        this->isEmpty = true;
    }
}

//QString getName() {
//  return name;
//}

//void RubikRaceElement::ElementReleased( ) {
//    qDebug() << "ElementReleased";
//}
