#include "labelsmanager.h"

LabelsManager::LabelsManager(int hp, int power, int potions, int gold)
{
    int width = 1536;
    QBrush brush(QColor(30, 30, 30));
    panel = new QGraphicsRectItem(0, 0, width, 100);
    panel->setBrush(brush);

    TextItem * healthText = new TextItem(QString("Health: ")+ QString::number(hp), QPoint(20, 10));
    healthText->setObjectName("health");
    TextItem * damageText = new TextItem(QString("Power: ")+ QString::number(power), QPoint(20, 50));
    damageText->setObjectName("damage");
    TextItem * potionsText = new TextItem(QString("Heals: ")+ QString::number(potions), QPoint(width-130, 10));
    potionsText->setObjectName("potions");
    TextItem * goldText = new TextItem(QString("Gold: ")+ QString::number(gold), QPoint(width-130, 50));
    goldText->setObjectName("gold");
    TextItem * lvlText = new TextItem(QString("LVL: 1"), QPoint(width/2 - 50, 20));
    lvlText->setObjectName("level");
    lvlText->setFont(QFont("Amoreiza", 30, QFont::Bold, false));

    labels.append(healthText);
    labels.append(damageText);
    labels.append(goldText);
    labels.append(potionsText);
    labels.append(lvlText);
}

void LabelsManager::updateLabelOf(QString objectName, int newData)
{
    foreach (TextItem * textItem, labels) {
        if (textItem->objectName() == objectName) {
            QString dataName = textItem->toPlainText().split(":").at(0);
            textItem->setPlainText(dataName + ": " + QString::number(newData));
//            qDebug() << textItem->toPlainText();
            return;
       }
    }
}
