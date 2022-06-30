#ifndef ARROW_H
#define ARROW_H

#include "Directions.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Arrow : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Arrow(Directions direction);


private slots:
    void move();
signals:
    void orcKilled(int gold);

private:
    int Damage = 10;
    Directions direction;
    QRectF boundingRect() const override
    {
        qreal penWidth = 3;
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                      20 + penWidth, 20 + penWidth);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override
    {
        painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
    }
};

#endif // ARROW_H
