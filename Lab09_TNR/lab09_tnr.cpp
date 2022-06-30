#include "lab09_tnr.h"
#include "ui_lab09_tnr.h"

Lab09_TNR::Lab09_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab09_TNR)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
    SocialAccount_TNR * socialAcc = new SocialAccount_TNR("amy", "pass123");
    connect(socialAcc->signalEmitter, &SignalEmitter::BalanceUpdatedSignal, this, &Lab09_TNR::UpdateBalance);
    connect(socialAcc->signalEmitter, &SignalEmitter::HistoryUpdatedSignal, this, &Lab09_TNR::UpdateHistory);
    prints.append(socialAcc->print());
    accounts.append(socialAcc);
    VIPAccount_TNR * vipAcc = new VIPAccount_TNR("vip", "pass124");
    connect(vipAcc->signalEmitter, &SignalEmitter::BalanceUpdatedSignal, this, &Lab09_TNR::UpdateBalance);
    connect(vipAcc->signalEmitter, &SignalEmitter::HistoryUpdatedSignal, this, &Lab09_TNR::UpdateHistory);
    connect(vipAcc->signalEmitter, &SignalEmitter::CreditUpdatedSignal, this, &Lab09_TNR::UpdateCredit);
    prints.append(vipAcc->print());
    accounts.append(vipAcc);
    BankAccount_TNR * bankAcc = new BankAccount_TNR("bank", "pass125");
    connect(bankAcc->signalEmitter, &SignalEmitter::BalanceUpdatedSignal, this, &Lab09_TNR::UpdateBalance);
    connect(bankAcc->signalEmitter, &SignalEmitter::HistoryUpdatedSignal, this, &Lab09_TNR::UpdateHistory);
    prints.append(bankAcc->print());
    accounts.append(bankAcc);
}

Lab09_TNR::~Lab09_TNR()
{
    for (Account_TNR * acc : accounts)
        delete acc;
    delete ui;
}

void Lab09_TNR::on_AddAccountBtn_clicked()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    newTab->setObjectName("tab_" + QString::number(tabsCreated));
    tabsCreated++;
    ui->tabWidget->addTab(newTab, tr("New Account"));
    LogInInterface(newTab);
    newTab->show();

}


void Lab09_TNR::FinishVipOperation(QString operation, double amount, QString username)
{

    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    VIPAccount_TNR * acc = dynamic_cast<VIPAccount_TNR *>(accounts.at(accID));
    QLabel * message = ui->tabWidget->currentWidget()->findChild<QLabel*>("message_" + acc->GetUsername());
    if (operation == "utilitiesBtn_"  + acc->GetUsername()) {
        if (!acc->PayUtilities(amount)) {
            message->setText("Can't pay utilities!");
        }
    } else if (operation == "cashBtn_" + acc->GetUsername()) {
        if (!acc->WithdrawCash(amount)) {
            message->setText("Can't withdraw cash");
        }
    } else if (operation == "transferBtn_" + acc->GetUsername()) {
        for (Account_TNR * account : accounts) {
            if (account->GetUsername() == username) {
                acc->TransferTo(account, amount);
            }
        }
    } else if (operation == "creditBtn_" + acc->GetUsername()) {
        if (!acc->TakeCredit(amount)) {
            message->setText("Can't take credit");
        }
    } else if (operation == "payCreditBtn_" + acc->GetUsername()) {
        if (!acc->PayCredit(amount)) {
            message->setText("Can't pay credit");
        }
    }
}

void Lab09_TNR::FinishComOperation(QString operation, double amount, QString username)
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    Account_TNR * acc = accounts.at(accID);
    QLabel * message = ui->tabWidget->currentWidget()->findChild<QLabel*>("message_" + acc->GetUsername());
    if (operation == "utilitiesBtn_"  + acc->GetUsername()) {
        if (!acc->PayUtilities(amount)) {
            message->setText("Can't pay utilities!");
        }
    } else if (operation == "cashBtn_" + acc->GetUsername()) {
        if (!acc->WithdrawCash(amount)) {
            message->setText("Can't withdraw cash");
        }
    } else if (operation == "transferBtn_" + acc->GetUsername()) {
        for (Account_TNR * account : accounts) {
            if (account->GetUsername() == username) {
                acc->TransferTo(account, amount);
            }
        }
    }
}

void Lab09_TNR::UpdateBalance(QString username, double balance)
{
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == username) {
            QList<QLabel *> balanceLabels = this->findChildren<QLabel*>("balance_" + username);
            for (QLabel * label : balanceLabels) {
                label->setText(QString::number(balance));
            }
        }
    }
}

void Lab09_TNR::UpdateCredit(QString username, double credit)
{
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == username) {
            ui->tabWidget->currentWidget()->findChild<QLabel*>("credit_" + username)->setText(
                        "Credit: " + QString::number(credit));
            ui->tabWidget->currentWidget()->findChild<QLabel*>("creditLimit_" + username)->setText(
                        "Credit Limit: " + QString::number(accounts.at(i)->CreditLimit - credit));
        }
   }
}

void Lab09_TNR::UpdateHistory(QString username, QString item)
{
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == username) {
            QList<QListWidget*> accHistories = this->findChildren<QListWidget*>("history_" + username);
            for (QListWidget* history : accHistories) {
                history->addItem(item);
            }
        }
    }
}

void Lab09_TNR::CommonInterface(Account_TNR * acc, int accID)
{
    QWidget *tab = ui->tabWidget->currentWidget();
    QString username = acc->GetUsername();
    QString tabName = acc->GetUsername()  + (acc->CanGetPayment() ? " - Social" : " - Common");

    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), acc->GetUsername() + " - Social");
    tab->setObjectName(tab->objectName() + "_" + QString::number(accID));

    FillBasicInterface(username, acc->GetBalance(), acc->GetHistory(), SLOT(CreateCommonForm()));
    if (acc->CanGetPayment())
        AddButtonToTab("socialBtn_"  + username,  "Get Social Payment", SLOT(SocialPayment()));

}

void Lab09_TNR::VIPInterface(Account_TNR * account, int accID)
{
    VIPAccount_TNR * acc = dynamic_cast<VIPAccount_TNR *>(account);
    QWidget *tab = ui->tabWidget->currentWidget();
    QString username = acc->GetUsername();

    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), username + " - Vip");
    tab->setObjectName(tab->objectName() + "_" + QString::number(accID));

    FillBasicInterface(username, acc->GetBalance(), acc->GetHistory(), SLOT(CreateVipForm()));

    QLabel * creditLimit = new QLabel("Credit limit: " + QString::number(acc->GetCreditLimit() - acc->GetCredit()), tab);
    creditLimit->setObjectName("creditLimit_"  + username);
    creditLimit->move(450, 100);
    creditLimit->show();

    QLabel * credit = new QLabel("Credit: " + QString::number(acc->GetCredit()), tab);
    credit->setObjectName("credit_"  + username);
    credit->move(450, 150);
    credit->setGeometry(450, 140, 100, 30);
    credit->show();

    AddButtonToTab("socialBtn_"  + username,  "Get Social Payment", SLOT(VipPayment()));
    AddButtonToTab("creditBtn_"  + username,  "Get Credit", SLOT(CreateVipForm()));
    AddButtonToTab("payCreditBtn_"  + username,  "Pay Credit", SLOT(CreateVipForm()));

}


void Lab09_TNR::CreateVipForm()
{
    QPushButton * btn = (QPushButton *) sender();
    Form * form = new Form(btn->objectName());
    connect(form, &Form::doneSignal, this, &Lab09_TNR::FinishVipOperation);
    form->show();
}

void Lab09_TNR::CreateCommonForm()
{
    QPushButton * btn = (QPushButton *) sender();
    Form * form = new Form(btn->objectName());
    connect(form, &Form::doneSignal, this, &Lab09_TNR::FinishComOperation);
    form->show();
}

void Lab09_TNR::LogInInterface(QWidget * tab)
{
    QLabel * loginLabel = new QLabel("Username: ", tab);
    loginLabel->move(250, 100);
    loginLabel->show();
    QLineEdit * loginEdit = new QLineEdit(tab);
    loginEdit->move(250, 140);
    loginEdit->setObjectName("username_" + QString::number(tabsCreated));
    loginEdit->show();
    QLabel * pswLabel = new QLabel("Password: ", tab);
    pswLabel->move(250, 180);
    pswLabel->show();
    QLineEdit * pswEdit = new QLineEdit(tab);
    pswEdit->move(250, 220);
    pswEdit->setObjectName("password_" + QString::number(tabsCreated));
    pswEdit->show();
    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Log In"), tab);
    connect(button, &QPushButton::pressed, this, &Lab09_TNR::LogIn_pressed);
    button->move(250, 260);
    button->show();
}

void Lab09_TNR::SocialPayment()
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    Account_TNR * acc = accounts.at(accID);
    acc->GetSocialPayment();
}

void Lab09_TNR::VipPayment()
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    Account_TNR * acc = accounts.at(accID);
    acc->GetSocialPayment();
}

void Lab09_TNR::LogIn_pressed()
{
    QString username, password;
    QList<QLineEdit *> lines = ui->tabWidget->currentWidget()->findChildren<QLineEdit *>();
    for (QLineEdit * line : lines) {
        if (line->objectName().contains("username")) {
            username = line->text();
        } else if (line->objectName().contains("password")) {
            password = line->text();
        }
    }
    for (int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->CheckAccount(username, password)) {
            while ( QWidget* w = ui->tabWidget->currentWidget()->findChild<QWidget*>() )
                delete w;
            if (accounts.at(i)->CreditLimit > 0) {
                VIPInterface(accounts.at(i), i);
            } else {
                CommonInterface(accounts.at(i), i);
            }
        }

    }
}

void Lab09_TNR::FillBasicInterface(QString username, double accBalance, QList<QString> history, const char *slot)
{
    QWidget * tab = ui->tabWidget->currentWidget();
    QFont boldBigFont( "Arial", 20, QFont::Bold);

    QLabel * label = new QLabel("Your balance: ", tab);
    label->move(90, 70);
    label->show();

    QLabel * balance = new QLabel(QString::number(accBalance), tab);
    balance->move(100, 100);
    balance->setGeometry(100, 100, 100, 30);
    balance->setObjectName("balance_" + username);
    balance->setFont(boldBigFont);
    balance->show();

    QLabel * header = new QLabel("Welcome, " + username, tab);
    header->setFont(boldBigFont);
    header->move(250, 50);
    header->setGeometry(300, 25, 250, 50);
    header->setObjectName("header_" + username);
    header->show();

    QLabel * msg = new QLabel("Good to see you!", tab);
    msg->move(250, 50);
    msg->setGeometry(300, 55, 250, 30);
    msg->setObjectName("message_" + username);
    msg->show();

    QListWidget * list = new QListWidget(tab);
    list->setObjectName("history_" + username);
    list->move(400, 200);
    for (QString& str : history) {
        list->addItem(str);
    }
    list->show();

    curButtonY = 140;
    AddButtonToTab("transferBtn_"  + username,  "Transfer To", slot);
    AddButtonToTab("utilitiesBtn_"  + username,  "Pay Utilities", slot);
    AddButtonToTab("cashBtn_"  + username,  "Withdraw Cash", slot);

}

void Lab09_TNR::AddButtonToTab(QString objectName, QString label, const char *slot)
{
    QWidget * tab = ui->tabWidget->currentWidget();
    QPushButton * btn = new QPushButton(label, tab);
    btn->setObjectName(objectName);
    connect(btn, SIGNAL(pressed()), this, slot);
    btn->move(100, curButtonY);
    curButtonY += 40;
    btn->show();
}


void Lab09_TNR::on_print_tnr_pressed()
{
    QListWidget * list = new QListWidget(ui->tabWidget->currentWidget());
    list->move(100, 300);
    for (QString& str : prints) {
        list->addItem(str);
    }
    list->show();
}

