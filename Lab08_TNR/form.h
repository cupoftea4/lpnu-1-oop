#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QObject>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QString operation, QWidget *parent = nullptr);
    void AddUsername();
    ~Form();

private slots:
    void on_doneBtn_clicked();

private:
    Ui::Form *ui;
    QString operation;
signals:
    void doneSignal(QString operation, double amount, QString username = "");
};

#endif // FORM_H
