#ifndef LAB09_TNR_H
#define LAB09_TNR_H

#include <QMainWindow>
#include <vipaccount_tnr.h>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <form.h>

#include <iostream>
#include <typeinfo>
#include <typeindex>

QT_BEGIN_NAMESPACE
namespace Ui { class Lab09_TNR; }
QT_END_NAMESPACE

class Lab09_TNR : public QMainWindow
{
        Q_OBJECT

    public:
        Lab09_TNR(QWidget *parent = nullptr);
        ~Lab09_TNR();

    private slots:
        void on_AddAccountBtn_clicked();
//        void FinishSocialOperation(QString operatin, double amount, QString username);
        void FinishVipOperation(QString operatin, double amount, QString username);
        void FinishComOperation(QString operatin, double amount, QString username);
        void UpdateBalance(QString username, double balance);
        void UpdateCredit(QString username, double credit);
        void UpdateHistory(QString username, QString item);

//        void CreateSocialForm();
        void CreateVipForm();
        void CreateCommonForm();

        void SocialPayment();
        void VipPayment();

        void on_print_tnr_pressed();

    private:
        int curButtonY;
        void LogInInterface(QWidget * tab);
//        void SocialInterface(Account_TNR * acc, int accID);
        void VIPInterface(Account_TNR * acc, int accID);
        void CommonInterface(Account_TNR * acc, int accID);


        void LogIn_pressed();
        void FillBasicInterface(QString username, double balance, QList<QString> history, const char *slot);
        void AddButtonToTab(QString objectName, QString label, const char* slot);
        Ui::Lab09_TNR *ui;
        QList<Account_TNR *> accounts;
        int tabsCreated = 0;
        QList<QString> prints;
    };
#endif // LAB09_TNR_H
