#ifndef ORC_H
#define ORC_H

#include "creature.h"
#include <QObject>
#include <QGraphicsScene>

class Orc: public Creature
{
    Q_OBJECT
public:
    Orc(int lvl);
    void updateHP(int hp) {
        int newHP = getHP() + hp;
        if (newHP <= 0) {
            killed();
        }
        setHP(newHP);
    }
    static int getOrcsCount() { return orcsCount; }
    ~Orc();
private slots:
    void Attack();

signals:
    void orcDiedSignal(QString id);

private:
    static int orcsCount;
    int level;
    void killed();
};

#endif // ORC_H
