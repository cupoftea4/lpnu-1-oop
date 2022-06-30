#ifndef HEALPOTIONSPAWNER_H
#define HEALPOTIONSPAWNER_H

#include "healpotion.h"

class HealPotionSpawner
{
public:
    HealPotionSpawner();
    QList<HealPotion *> healPotions;
private:
    void SpawnHealPotions(int quantity);
};

#endif // HEALPOTIONSPAWNER_H
