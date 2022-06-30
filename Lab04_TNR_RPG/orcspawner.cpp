#include "orcspawner.h"
#include <QUuid>

OrcSpawner::OrcSpawner()
{
    spawnOrcs(1, 4);
}

OrcSpawner::OrcSpawner(int lvl)
{
        spawnOrcs(lvl, 5);
}

void OrcSpawner::handleOrcDeath(QString id)
{
    for(int i = 0; i < orcs.length(); i++) {
        if (orcs.at(i)->objectName() == id) {
            orcs.removeAt(i);
            if (!orcs.length()) {
                emit allOrcsDiedSignal();
            }
            return;
        }
    }
}

void OrcSpawner::spawnOrcs(int lvl, int quantity)
{
    for(int i = 0; i < quantity; i++) {
        Orc * orc = new Orc(lvl);
        orc->setObjectName(QUuid::createUuid().toString());
        QObject::connect(orc, &Orc::orcDiedSignal, this, &OrcSpawner::handleOrcDeath);
        orc->setPos(rand()%1000, rand()%600+100);
        orcs.append(orc);
    }
}
