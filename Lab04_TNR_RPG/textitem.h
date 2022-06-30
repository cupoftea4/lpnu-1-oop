#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <QGraphicsTextItem>
#include <QPoint>
#include <QFont>

class TextItem : public QGraphicsTextItem
{
public:
    TextItem(QString text, QPoint position);
    void updateText(QString newText);
};

#endif // TEXTITEM_H
