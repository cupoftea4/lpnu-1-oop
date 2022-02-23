#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    QString calculate(double secondOperand);
    void onClick(QString buttonName, const char* slot);
    void setDisplay(QString string);
    bool compareQStrings(QString str1, QString str2);

private slots:
    void NumPressed();
    void MathButtonPressed();
    void OperationButtonPressed();
    void EqualsButton();
    void Clear();
};
#endif // CALCULATOR_H
