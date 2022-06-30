#ifndef ORCSPAWNER_H
#define ORCSPAWNER_H
#include <QList>
#include <orc.h>
#include <QGraphicsScene>
#include <QObject>

class OrcSpawner : public QObject
{
    Q_OBJECT
public:
    OrcSpawner();
    OrcSpawner(int lvl);
    QList<Orc *> orcs;
public slots:
    void handleOrcDeath(QString id);

private:
    void spawnOrcs(int lvl, int quantity);

signals:
    void allOrcsDiedSignal();

private slots:
    void AllOrcsDied() {
        orcs.clear();
        emit allOrcsDiedSignal();
    };
};

#endif // ORCSPAWNER_H
