#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsItem>
#include <QPainter>

class MyRect : public QGraphicsItem
{
public:
    QRectF boundingRect() const override
    {
        qreal penWidth = 1;
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                      20 + penWidth, 20 + penWidth);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override
    {
        painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
    }

private:
    void onKeyPressed(QKeyEvent * event);
};
#endif // MYRECT_H
