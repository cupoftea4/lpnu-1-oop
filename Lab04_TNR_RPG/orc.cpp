#include "orc.h"
#include <QTimer>
#include "hero.h"

Orc::Orc(int lvl): Creature()
{
    orcsCount++;
    QPixmap * orcPic = new QPixmap();
    if (lvl == 1) {
        orcPic->load(":/sprites/sprites/Chmonia_token.png");
    } else if (lvl == 2) {
        orcPic->load(":/sprites/sprites/Orc2_token.png");
    } else {
        orcPic->load(":/sprites/sprites/Orc3_token.png");
    }
    QPixmap scaledPixmap = orcPic->scaled(QSize(80, 80));
    setPixmap(scaledPixmap);

    setHP(lvl*10);
    setDamage(lvl*5);
    setGold(lvl*10);
    level = lvl;

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Orc::Attack);
    timer->start(2000);
}

Orc::~Orc()
{

}

int Orc::orcsCount = 0;

void Orc::Attack()
{
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0, n = collidingItemsList.size(); i < n; ++i ) {
        if (typeid (*(collidingItemsList.at(i))) == typeid(Hero)) {
            Hero * hero = (Hero *)collidingItemsList.at(i);
            hero->updateHP(-getDamage());
            return;
        }
    }
}

void Orc::killed()
{
    orcsCount--;
    emit orcDiedSignal(this->objectName());
    scene()->removeItem(this);
    delete this;
}

