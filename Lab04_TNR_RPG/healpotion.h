#ifndef HEALPOTION_H
#define HEALPOTION_H

#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>

class HealPotion : public QGraphicsPixmapItem
{
public:
    HealPotion();
    void AddPotion();
private:

//    QRectF boundingRect() const override
//    {
//        qreal penWidth = 1;
//        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
//                      20 + penWidth, 20 + penWidth);
//    }

//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
//               QWidget *widget) override
//    {
//        painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
////        painter->drawRoundedRect()
//    }
};

#endif // HEALPOTION_H
