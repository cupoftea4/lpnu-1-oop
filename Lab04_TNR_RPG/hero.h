#ifndef HERO_H
#define HERO_H

#include <QWidget>
#include <QPoint>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "creature.h"
#include "Directions.h"
#include "labelsmanager.h"

class Hero : public Creature
{
    Q_OBJECT
public:
    Hero();
    int HealPotionsCount() { return healPotionsCount; }
    void addHealPotion(int potion);
    void keyPressEvent(QKeyEvent * event);

    void updateGold(int goldToAdd);
    void updateHP(int hpToAdd);
    void powerUp();

    LabelsManager * GetLabelsManager() { return labelsManager; };
    virtual ~Hero() { delete labelsManager; };

private slots:
    void updateLabels(QString objectName, int newData);
    void Heal();
    void PowerUp();
    void EnableAttack();

signals:
    void updateLabelsSignal(QString objectName, int newData);
    void killedSignal();
    void allOrcsDiedSignal();

private:
    LabelsManager * labelsManager;
    const int DamageBoost = 4;
    int arrows = 20;
    int healPotionsCount = 0;
    bool canAttack = true;
    Directions curDirection;

    QMediaPlayer * damageSound;
    void killed();
};

#endif // HERO_H
