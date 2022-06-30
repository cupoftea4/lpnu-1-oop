#include "form.h"
#include "ui_form.h"

Form::Form(QString operation, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    operation(operation)
{
    ui->setupUi(this);
    this->setWindowTitle(operation);
    if (operation.contains("transferBtn")) {
        AddUsername();
    }
}

void Form::AddUsername()
{
    QLabel * label = new QLabel("Username: ", this);
    label->move(120, 130);
    label->show();
    QLineEdit * username = new QLineEdit(this);
    username->setObjectName("username");
    username->setText("vip");
    username->move(120, 150);
    username->show();
}

Form::~Form()
{
    delete ui;
}

void Form::on_doneBtn_clicked()
{
    if (operation.contains("transferBtn")) {
        emit doneSignal(operation, ui->doubleSpinBox->value(), this->findChild<QLineEdit *>("username")->text());
    } else {
        emit doneSignal(operation, ui->doubleSpinBox->value());
    }

    this->close();
}

