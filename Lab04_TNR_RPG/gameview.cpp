#include "gameview.h"
#include <QDebug>
#include <QApplication>

GameView::GameView()
{
    setWindowTitle("Бандерогусь");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowState(Qt::WindowMaximized);
    setWindowIcon(QIcon(":/sprites/sprites/Kozak_token.png"));
}

QGraphicsScene *GameView::setUpScene()
{
        QGraphicsScene * scene = new QGraphicsScene();
        QPixmap bgPic(":/sprites/sprites/bgLvl1.jpg");
        scene->setBackgroundBrush(bgPic.scaled(viewW, viewH));

        if (!heroCreated) {
            hero = new Hero();
            heroCreated = true;
            QObject::connect(hero, &Hero::killedSignal, this, &GameView::restartWindow);
            QObject::connect(hero, &Hero::allOrcsDiedSignal, this, &GameView::loadNextLevel);
        }
        hero->setFlag(QGraphicsItem::ItemIsFocusable);
        hero->setFocus();
        hero->setPos(viewW/2 - 100, viewH/2 - 100);
        scene->addItem(hero);

        OrcSpawner * orcSpawner = new OrcSpawner(level);
        int orcsCount = orcSpawner->orcs.size();
        QObject::connect(orcSpawner, &OrcSpawner::allOrcsDiedSignal, this, &GameView::loadNextLevel);
        for (int i = 0; i < orcsCount; i++) {
            scene->addItem(orcSpawner->orcs.at(i));
        }

        HealPotionSpawner * potSpawner = new HealPotionSpawner();
        int potCount = potSpawner->healPotions.size();
        for (int i = 0; i < potCount; i++) {
            scene->addItem(potSpawner->healPotions.at(i));
        }

        LabelsManager * labelsManager = hero->GetLabelsManager();
        scene->addItem(labelsManager->getPanel());
        int labelsCount = labelsManager->getLabels().size();
        for (int i = 0; i < labelsCount; i++) {
            scene->addItem(labelsManager->getLabels().at(i));
        }

        QFont btnsFont("Amoreiza", 16, QFont::Normal, false);
        QPushButton * healBtn = new QPushButton();
        healBtn->setText("Heal(+10hp)");
        healBtn->setFont(btnsFont);
        healBtn->setToolTip("Or press F (to pay respect)");
        healBtn->setGeometry(viewW - 200, viewH - 200, 180, 40);
        QObject::connect(healBtn, SIGNAL(pressed()), hero, SLOT(Heal()));
        scene->addWidget(healBtn);

        QPushButton * powerBtn = new QPushButton();
        powerBtn->setText("Power Up(30gd)");
        powerBtn->setFont(btnsFont);
        powerBtn->setToolTip("Or press G");
        powerBtn->setGeometry(viewW - 200, viewH - 150, 180, 40);
        QObject::connect(powerBtn, SIGNAL(pressed()), hero, SLOT(PowerUp()));
        scene->addWidget(powerBtn);
        scene->setSceneRect(0, 0, viewW, viewH-70);

        setScene(scene);
        return scene;
}

void GameView::loadNextLevel()
{
    if (UpdateLevel(level+1)) {
        setUpScene();
    }
}

void GameView::closeGame()
{
    this->close();
    delete this;
}

void GameView::ResetGame()
{
    UpdateLevel(1);
    heroCreated = false;
}

bool GameView::UpdateLevel(int newLvl)
{
    if (newLvl > 3) {
        ResetGame();
        Message * msg = new Message("Congrats! You won!");
        QObject::connect(msg, &Message::restartSignal, this, &GameView::setUpScene);
//        QObject::connect(msg, &Message::closeGameSignal, this, &GameView::closeGame);
        msg->show();
        return false;
    } else {
        level = newLvl;
        hero->GetLabelsManager()->updateLabelOf("level", level);
        return true;
    }
}

void GameView::restartWindow()
{
    ResetGame();
    Message * msg = new Message("So I guess you died");
    QObject::connect(msg, &Message::restartSignal, this, &GameView::setUpScene);
//    QObject::connect(msg, &Message::closeGameSignal, this, &GameView::closeGame);
    msg->show();
}



