#ifndef LAB08_TNR_H
#define LAB08_TNR_H

#include <QMainWindow>
#include <socialaccount_tnr.h>
#include <vipaccount_tnr.h>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <form.h>

#include <iostream>
#include <typeinfo>
#include <typeindex>

QT_BEGIN_NAMESPACE
namespace Ui { class Lab08_TNR; }
QT_END_NAMESPACE

class Lab08_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Lab08_TNR(QWidget *parent = nullptr);
    ~Lab08_TNR();

private slots:
    void on_AddAccountBtn_clicked();
    void FinishSocialOperation(QString operatin, double amount, QString username);
    void FinishVipOperation(QString operatin, double amount, QString username);
    void FinishComOperation(QString operatin, double amount, QString username);
    void UpdateBalance(double balance);
    void UpdateCredit(double credit);
    void UpdateHistory(QString item);

    void CreateSocialForm();
    void CreateVipForm();
    void CreateCommonForm();

    void SocialPayment();
    void VipPayment();

    void on_print_tnr_pressed();

private:
    int curButtonY;
    void LogInInterface(QWidget * tab);
    void SocialInterface(SocialAccount_TNR * acc, int accID);
    void VIPInterface(VIPAccount_TNR * acc, int accID);
    void CommonInterface(BankAccount_TNR * acc, int accID);


    void LogIn_pressed();
    void FillBasicInterface(QString username, double balance, QList<QString> history, const char *slot);
    void AddButtonToTab(QString objectName, QString label, const char* slot);
    Ui::Lab08_TNR *ui;
    QList<BankAccount_TNR *> accounts;
    int tabsCreated = 0;
    QList<QString> prints;
};
#endif // LAB08_TNR_H
