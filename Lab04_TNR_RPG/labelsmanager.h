#ifndef LABELSMANAGER_H
#define LABELSMANAGER_H

#include <QList>
#include <QBrush>
#include <QGraphicsRectItem>
#include "textitem.h"
//#include "gameview.h"

class LabelsManager : public QObject
{
public:
    LabelsManager(int hp, int power, int potions, int gold);
    QList<TextItem *> getLabels() { return labels; }
    void updateLabelOf(QString objectName, int newData);
    QGraphicsRectItem* getPanel() { return panel; }

private:
    QList <TextItem *> labels;
    QGraphicsRectItem* panel;

};

#endif // LABELSMANAGER_H
