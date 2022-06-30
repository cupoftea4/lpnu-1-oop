#include "hero.h"
#include "arrow.h"
#include "healpotion.h"
#include "toastmsg.h"
#include "orc.h"
#include <QUrl>
#include <QMediaPlayer>


Hero::Hero() : Creature(10, 20, 5)
{
    QPixmap pixmap(":/sprites/sprites/Kozak_token.png");
    QPixmap scaledPixmap = pixmap.scaled(QSize(90, 90));
    setPixmap(scaledPixmap);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    healPotionsCount = 0;
    labelsManager = new LabelsManager(getHP(), getDamage(), HealPotionsCount(), getGold());
    QObject::connect(this, &Hero::updateLabelsSignal, this, &Hero::updateLabels);

}

void Hero::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << event->key() << " " << Qt::Key_E;
//    qDebug() << "aaaa";

    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0, n = collidingItemsList.size(); i < n; ++i ) {
        if (typeid (*(collidingItemsList.at(i))) == typeid(HealPotion)) {
            addHealPotion(1);
            scene()->removeItem(collidingItemsList.at(i));
            delete collidingItemsList.at(i);
        }
    }
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        if (x() > 0)
            setPos(x() - 10, y());
        curDirection = Left;
    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        if (x() < scene()->width())
            setPos(x() + 10, y());
        curDirection = Right;
    } else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        if (y() > 120)
            setPos(x(), y() - 10);
        curDirection = Up;
    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        if (y() < scene()->height()-100)
            setPos(x(), y() + 10);
        curDirection = Down;
    } else if (event->key() == Qt::Key_E) {
        if (arrows > 0) {
            Arrow * arrow = new Arrow(curDirection);
            QObject::connect(arrow, &Arrow::orcKilled, this, &Hero::updateGold);
            arrow->setPos(x()+ pixmap().size().width()/2, y()+pixmap().size().height()/2);
            scene()->addItem(arrow);
            arrows--;
            new ToastMsg(QString::number(arrows) + " arrows left.");
        } else {
            new ToastMsg("No Arrows.");
            return;
        }
    } else if (event->key() == Qt::Key_H) {
        Heal();
    } else if (event->key() == Qt::Key_G) {
        PowerUp();
    } else if (event->key() == Qt::Key_F) {
        if (canAttack) {
            canAttack = false;
            QTimer::singleShot(500, this, SLOT(EnableAttack()));
        } else {
            new ToastMsg("Too soon");
            return;
        }
        for (int i = 0, n = collidingItemsList.size(); i < n; ++i ) {
            if (typeid (*(collidingItemsList.at(i))) == typeid(Orc)) {
                Orc * orc = (Orc *)collidingItemsList.at(i);
                qDebug() << orc->getOrcsCount();
                orc->updateHP(-getDamage());
                updateGold(orc->getGold());
                arrows++;
            }
        }
    }
}

void Hero::addHealPotion(int potion) {
    if (potion > 0) {
        healPotionsCount++;
    } else if (potion < 0) {
        healPotionsCount--;
    }
    emit updateLabelsSignal("potions", healPotionsCount);
}

void Hero::updateGold(int gold)
{
    setGold(getGold() + gold);
    emit updateLabelsSignal("gold", getGold());
}

void Hero::updateHP(int hp)
{
    int newHp = getHP() + hp;
    if (newHp <= 0) {
        emit killedSignal();
        killed();
        return;
    } else {
        setHP(getHP() + hp);
        emit updateLabelsSignal("health", getHP());
    }
}

void Hero::powerUp()
{
    setDamage(getDamage() + DamageBoost);
    emit updateLabelsSignal("damage", getDamage());
}

void Hero::updateLabels(QString objectName, int newData)
{
    labelsManager->updateLabelOf(objectName, newData);
}

void Hero::Heal()
{
    setFocus();
    if (healPotionsCount > 0) {
        updateHP(10);
        addHealPotion(-1);
        new ToastMsg("+10 HP!");
    }
}

void Hero::PowerUp()
{
    setFocus();
    if (getGold() >= 30) {
        updateGold(-30);
        powerUp();
        new ToastMsg("Power Up!");
    }
}

void Hero::EnableAttack()
{
    canAttack = true;
}

void Hero::killed()
{
    scene()->removeItem(this);
    delete this;
}




