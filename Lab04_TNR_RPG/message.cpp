#include "message.h"
#include "ui_message.h"

Message::Message(QString msg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);
    connect(ui->restartBtn, SIGNAL(pressed()), this, SLOT(Restart()));
//    connect(ui->closeBtn, SIGNAL(pressed()), this, SLOT(close()));
    setWindowFlags( Qt::FramelessWindowHint | Qt::Dialog );
    ui->label->setText(msg);
}


Message::~Message()
{
    delete ui;
}

void Message::Restart()
{
    emit restartSignal();
    close();
    delete this;
}

void Message::CloseGame()
{
    emit closeGameSignal();
    close();
    delete this;
}
