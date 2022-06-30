#ifndef CREATURE_H
#define CREATURE_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class Creature : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Creature();
    Creature(int HP, int gold, int damage);
//    ~Creature();
    int getHP() {
        return HP;
    }
    void setHP(int newHP) {
        if(newHP >= 0 && newHP <= 100) HP = newHP;
    }
    int getGold() {
        return gold;
    }
    void setGold(int newGold) {
        if(newGold >= 0 && newGold <= 100) gold = newGold;
    }
    int getDamage() {
        return damage;
    }
    void setDamage(int newDamage) {
        if(newDamage >= 0 && newDamage <= 30) damage = newDamage;
    }
    static void setSceneSize(int w, int h) { sceneW = w; sceneH = h; }
    static int SceneW() { return sceneW; }
    static int SceneH() { return sceneH; }

private:
    int HP = 0;
    int gold = 0;
    int damage = 0;
    static int sceneW;
    static int sceneH;


};

#endif // CREATURE_H
