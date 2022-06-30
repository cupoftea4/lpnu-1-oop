#include "healpotionspawner.h"

HealPotionSpawner::HealPotionSpawner()
{
    SpawnHealPotions(5);
}

void HealPotionSpawner::SpawnHealPotions(int count)
{
    for(int i = 0; i < count; i++) {
        HealPotion * potion = new HealPotion();
        potion->setPos(rand()%1000, rand()%600+100);
        healPotions.append(potion);
    }
}
