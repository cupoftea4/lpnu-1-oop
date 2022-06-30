#include "toastmsg.h"
#include "ui_toastmsg.h"

ToastMsg::ToastMsg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToastMsg)
{
    ui->setupUi(this);
}

ToastMsg::ToastMsg(QString msg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToastMsg)
{
    ui->setupUi(this);
    ui->label->setText(msg);
    ui->label->setGeometry(10, 10, msg.length()*10, 20);
    setAutoClose(true);
    setTimeout(1);
    setWindowFlags( Qt::FramelessWindowHint | Qt::Dialog );
    setGeometry(690, 600, msg.length()*10+20, 40);
    this->show();
}

ToastMsg::~ToastMsg()
{
    delete ui;
}
