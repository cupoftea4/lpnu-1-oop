#include "healpotion.h"

HealPotion::HealPotion()
{
    QPixmap pixmap(":/sprites/sprites/Potion.png");
    setPixmap(pixmap.scaled(QSize(50, 50)));
}

void HealPotion::AddPotion()
{

}
