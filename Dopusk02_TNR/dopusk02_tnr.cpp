#include "dopusk02_tnr.h"
#include "ui_dopusk02_tnr.h"

Dopusk02_TNR::Dopusk02_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dopusk02_TNR)
{
    ui->setupUi(this);
    QMap<QString, QColor> colors =
    {
        {"red", QColor(0, 255, 0)},
        {"green", QColor(0, 255, 0)},
        {"blue", QColor(0, 0, 255)},
    };
    QComboBox * colorPicker = Dopusk02_TNR::findChild<QComboBox *>("ColorPicker");
    colorPicker->addItems(colors.keys());
    Dopusk02_TNR::findChild<QFrame *>("EditPanel")->setVisible(false);
    onClick("EditButton", SLOT(EditPressed()));
    onClick("SetButton", SLOT(SetLabel()));
    onClick("CloseButton", SLOT(Close()));
    onClick("ByeButton", SLOT(Close()));
}

Dopusk02_TNR::~Dopusk02_TNR()
{
    delete ui;
}

void Dopusk02_TNR::EditPressed() {
    Dopusk02_TNR::findChild<QFrame *>("EditPanel")->setVisible(true);
}

void Dopusk02_TNR::SetLabel() {
    QString labelText = Dopusk02_TNR::findChild<QLineEdit *>("LabelEdit")->text();
//    QComboBox * colorPicker = Dopusk02_TNR::findChild<QComboBox *>("ColorPicker");
//    qDebug() << ui->ColorPicker->currentText();
    ui->label->setText(labelText);
    ui->label->setStyleSheet("QLabel { color : "+ui->ColorPicker->currentText()+"; }");
    Dopusk02_TNR::findChild<QFrame *>("EditPanel")->setVisible(false);
}

void Dopusk02_TNR::Close() {
    this->close();
}

void Dopusk02_TNR::onClick(QString buttonName, const char* slot) {
    QPushButton * button = Dopusk02_TNR::findChild<QPushButton *>(buttonName);
    connect(button, SIGNAL(released()), this, slot);
}
