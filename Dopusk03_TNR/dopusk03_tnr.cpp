#include "dopusk03_tnr.h"
#include "ui_dopusk03_tnr.h"
#include "dialog.h"

Dopusk03_TNR::Dopusk03_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dopusk03_TNR)
{
    ui->setupUi(this);
    qDebug()<<"File exists -"<<QFileInfo("cat.jpg").exists()<<" "<<QFileInfo("cat.jpg").absoluteFilePath();
    centralWidget()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(centralWidget(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(CtxMenu(const QPoint&)));
}

void Dopusk03_TNR::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Alt) {
        QList<QMenu*> menus = ui->menubar->findChildren<QMenu*>();
        menus[0]->setTitle("&File");
        menus[1]->setTitle("&Tool");
        menus[2]->setTitle("&Help");

    }
}

Dopusk03_TNR::~Dopusk03_TNR()
{
    delete ui;
}


void Dopusk03_TNR::on_actionEdit_triggered()
{
    QString labelText = ui->label->text();
    ui->lineEdit->setText(labelText);
}


void Dopusk03_TNR::on_actionKeep_triggered()
{
    QString lineEditText = ui->lineEdit->text();
    undoLineEditText = ui->label->text();
    ui->label->setText(lineEditText);
}


void Dopusk03_TNR::on_action_Undo_triggered()
{
    ui->action_Redo->setEnabled(true);

    redoLineEditText = ui->label->text();
    ui->label->setText(undoLineEditText);
}


void Dopusk03_TNR::on_action_About_triggered()
{
    Dialog * dialog = new Dialog();
    dialog->setModal(true);
    dialog->exec();
}


void Dopusk03_TNR::on_action_Exit_triggered()
{
    this->close();
}


void Dopusk03_TNR::on_action_Redo_triggered()
{
    ui->label->setText(redoLineEditText);
}

void Dopusk03_TNR::CtxMenu(const QPoint& pos){
    QPoint globalPos = centralWidget()->mapToGlobal(pos);

    QMenu myMenu;

    myMenu.addAction("Edit", this, SLOT(Edit()));
    myMenu.addAction("Keep", this, SLOT(Keep()));
    myMenu.addAction("Undo", this, SLOT(Undo()));
    myMenu.addAction("Redo", this, SLOT(Redo()));

    myMenu.exec(globalPos);
}

void Dopusk03_TNR::Edit() {
    on_actionEdit_triggered();
}

void Dopusk03_TNR::Keep() {
    on_actionKeep_triggered();
}

void Dopusk03_TNR::Undo() {
    on_action_Undo_triggered();
}

void Dopusk03_TNR::Redo() {
    on_action_Redo_triggered();
}

