#include <QList>
#include "arrow.h"
#include "orc.h"
#include "hero.h"
#include "labelsmanager.h"

Arrow::Arrow(Directions dir)
{
    direction = dir;
    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Arrow::move);
    timer->start(50);

}

void Arrow::move() {
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0, n = collidingItemsList.size(); i < n; ++i ) {
        if (typeid (*(collidingItemsList.at(i))) == typeid(Orc)) {
            Orc * orc = (Orc *)collidingItemsList.at(i);
            emit orcKilled(orc->getGold());
            orc->updateHP(-Damage);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if (direction == Left) {
        setPos(x()-10, y());
    } else if (direction == Right) {
        setPos(x()+10, y());
    } else if (direction == Up) {
        setPos(x(), y()-10);
    } else if (direction == Down) {
        setPos(x(), y()+10);
    }
    if (y() < 0 || x() < 0 || x() > scene()->width() || y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "deleted";
    }
}



