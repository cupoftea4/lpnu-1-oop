#include "calculator.h"
#include "ui_calculator.h"

/****************************************
TODO:
  - 2+2*3

*****************************************/

double calcVal = 0.0;
QString curOperation = "";

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    setDisplay(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; ++i) {
        QString btnName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(btnName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    onClick("ButtonPoint", SLOT(NumPressed()));

    QList<QPushButton *> buttons = Calculator::findChildren<QPushButton *>();
    for (const auto *btn: buttons) {
        QString btnName = btn->objectName();
        if (btnName.contains("MathBtn", Qt::CaseInsensitive)) {
            onClick(btnName, SLOT(MathButtonPressed()));
        } else if (btnName.contains("Btn", Qt::CaseInsensitive)) {
            onClick(btnName, SLOT(OperationButtonPressed()));
        }
    }
    onClick("ButtonEquals", SLOT(EqualsButton()));
    onClick("ButtonClear", SLOT(Clear()));
}

void Calculator::NumPressed() {
    QString newVal;
    QPushButton * button = (QPushButton * )sender();
    QString btnVal = button->text();
    QString displayVal = ui->Display->text();
    if (btnVal == "." && displayVal.contains(".")) return;
    if (displayVal.toDouble() == 0 && btnVal != "." && !displayVal.contains(".")) {
        setDisplay(btnVal);
    } else {
        newVal = displayVal + btnVal;
        setDisplay(newVal);
    }
}

void Calculator::MathButtonPressed() {
    qDebug() << calcVal << " " << curOperation;
    double displayVal = ui->Display->text().toDouble();
    if (curOperation != "") {
        calculate(displayVal);
    } else {
        calcVal = displayVal;
    }
    QPushButton * button = (QPushButton *)sender();
    curOperation = button->text();
    setDisplay("");

}

void Calculator::OperationButtonPressed() {
    QString newVal = "";
    double dblDisplayVal = ui->Display->text().toDouble();
    QPushButton * button = (QPushButton * )sender();
    QString btnName = button->objectName();
    if (compareQStrings(btnName,  "Btn1bySth")) {
        if (dblDisplayVal) {
            newVal = QString::number(1 / dblDisplayVal);
        } else {
            newVal = "∞";
        }
    } else if (compareQStrings(btnName,  "BtnPlusMinus")) {
        newVal = QString::number(-dblDisplayVal);
    } else if (compareQStrings(btnName,  "BtnPow2")) {
        newVal = QString::number(dblDisplayVal * dblDisplayVal);
    } else {
        return;
    }
    setDisplay(newVal);
}

void Calculator::EqualsButton() {
    double dblDisplayVal = ui->Display->text().toDouble();
    setDisplay(calculate(dblDisplayVal));
}

void Calculator::Clear() {
    setDisplay("0");
    curOperation = "";
}

QString Calculator::calculate(double secondOperand) {
    double result = 0.0;
    if (compareQStrings(curOperation, "+")) {
       result = calcVal + secondOperand;
    } else if (compareQStrings(curOperation, "-")) {
        result = calcVal - secondOperand;
    } else if (compareQStrings(curOperation,  "*")) {
        result = calcVal * secondOperand;
    } else if (compareQStrings(curOperation, "/")) {
        if(!secondOperand) return "Error";
        result = calcVal / secondOperand;
    } else {
        return "Error";
    }
    calcVal = result;
    curOperation = "";
    return QString::number(result, 'g', 13);
}

void Calculator::onClick(QString buttonName, const char* slot) {
    QPushButton * mathBtn = Calculator::findChild<QPushButton *>(buttonName);
    connect(mathBtn, SIGNAL(released()), this, slot);
}

void Calculator::setDisplay(QString string) {

    ui->Display->setText(string);
}

bool Calculator::compareQStrings(QString str1, QString str2) {
    return !QString::compare(str1, str2, Qt::CaseSensitive);
}

Calculator::~Calculator()
{
    delete ui;
}
