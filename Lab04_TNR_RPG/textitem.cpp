#include "textitem.h"

TextItem::TextItem(QString text, QPoint position)
{
    this->setPlainText(text);
    this->setPos(position);
    this->setDefaultTextColor(Qt::white);
    this->setFont(QFont("Amoreiza", 20, QFont::Normal, false));
}

void TextItem::updateText(QString newText)
{
    this->setPlainText(newText);
}
