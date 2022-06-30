#include "lab08_tnr.h"
#include "ui_lab08_tnr.h"

Lab08_TNR::Lab08_TNR(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab08_TNR)
{
    ui->setupUi(this);
    ui->tabWidget->clear();
    SocialAccount_TNR * socialAcc = new SocialAccount_TNR("amy", "pass123");
    connect(socialAcc, &SocialAccount_TNR::BalanceUpdatedSignal, this, &Lab08_TNR::UpdateBalance);
    connect(socialAcc, &SocialAccount_TNR::HistoryUpdatedSignal, this, &Lab08_TNR::UpdateHistory);
    prints.append(socialAcc->print());
    accounts.append(socialAcc);
    VIPAccount_TNR * vipAcc = new VIPAccount_TNR("vip", "pass124");
    connect(vipAcc, &VIPAccount_TNR::BalanceUpdatedSignal, this, &Lab08_TNR::UpdateBalance);
    connect(vipAcc, &VIPAccount_TNR::HistoryUpdatedSignal, this, &Lab08_TNR::UpdateHistory);
    connect(vipAcc, &VIPAccount_TNR::CreditUpdatedSignal, this, &Lab08_TNR::UpdateCredit);
    prints.append(vipAcc->print());
    accounts.append(vipAcc);
    BankAccount_TNR * bankAcc = new BankAccount_TNR("bank", "pass125");
    connect(bankAcc, &BankAccount_TNR::BalanceUpdatedSignal, this, &Lab08_TNR::UpdateBalance);
    connect(bankAcc, &BankAccount_TNR::HistoryUpdatedSignal, this, &Lab08_TNR::UpdateHistory);
    prints.append(bankAcc->print());
    accounts.append(bankAcc);
}

Lab08_TNR::~Lab08_TNR()
{
    for (BankAccount_TNR * acc : accounts)
        delete acc;
    delete ui;
}

void Lab08_TNR::on_AddAccountBtn_clicked()
{
    QWidget *newTab = new QWidget(ui->tabWidget);
    newTab->setObjectName("tab_" + QString::number(tabsCreated));
    tabsCreated++;
    ui->tabWidget->addTab(newTab, tr("New Account"));
    LogInInterface(newTab);
    newTab->show();

}

void Lab08_TNR::FinishSocialOperation(QString operation, double amount, QString username)
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    SocialAccount_TNR * acc = (SocialAccount_TNR *)accounts.at(accID);
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
        for (BankAccount_TNR * account : accounts) {

            if (account->GetUsername() == username) {
                acc->TransferTo(account, amount);
            }
        }
    }
}

void Lab08_TNR::FinishVipOperation(QString operation, double amount, QString username)
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    VIPAccount_TNR * acc = (VIPAccount_TNR *)accounts.at(accID);
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
        for (BankAccount_TNR * account : accounts) {
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

void Lab08_TNR::FinishComOperation(QString operation, double amount, QString username)
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    BankAccount_TNR * acc = (BankAccount_TNR *)accounts.at(accID);
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
        for (BankAccount_TNR * account : accounts) {
            if (account->GetUsername() == username) {
                acc->TransferTo(account, amount);
            }
        }
    }
}

void Lab08_TNR::UpdateBalance(double balance)
{
    BankAccount_TNR * senderAcc  =  (BankAccount_TNR *)sender();
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == senderAcc->GetUsername()) {
            QList<QLabel *> balanceLabels = this->findChildren<QLabel*>("balance_" + senderAcc->GetUsername());
            for (QLabel * label : balanceLabels) {
                label->setText(QString::number(balance));
            }
        }
    }
}

void Lab08_TNR::UpdateCredit(double credit)
{
    VIPAccount_TNR * senderAcc  =  (VIPAccount_TNR *)sender();
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == senderAcc->GetUsername()) {
            ui->tabWidget->currentWidget()->findChild<QLabel*>("credit_" + senderAcc->GetUsername())->setText(
                        "Credit: " + QString::number(credit));
            ui->tabWidget->currentWidget()->findChild<QLabel*>("creditLimit_" + senderAcc->GetUsername())->setText(
                        "Credit Limit: " + QString::number(senderAcc->GetCreditLimit() - credit));
        }
   }
}

void Lab08_TNR::UpdateHistory(QString item)
{
    BankAccount_TNR * senderAcc  =  (BankAccount_TNR *)sender();
    for(int i = 0; i < accounts.length(); i++) {
        if (accounts.at(i)->GetUsername() == senderAcc->GetUsername()) {
            QList<QListWidget*> accHistories = this->findChildren<QListWidget*>("history_" + senderAcc->GetUsername());
            for (QListWidget* history : accHistories) {
                history->addItem(item);
            }
        }
    }
}

void Lab08_TNR::SocialInterface(SocialAccount_TNR * acc, int accID)
{
    QWidget *tab = ui->tabWidget->currentWidget();
    QString username = acc->GetUsername();
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), acc->GetUsername() + " - Social");
    tab->setObjectName(tab->objectName() + "_" + QString::number(accID));

    FillBasicInterface(username, acc->GetBalance(), acc->GetHistory(), SLOT(CreateSocialForm()));
    AddButtonToTab("socialBtn_"  + username,  "Get Social Payment", SLOT(SocialPayment()));

}

void Lab08_TNR::VIPInterface(VIPAccount_TNR *acc, int accID)
{
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

void Lab08_TNR::CommonInterface(BankAccount_TNR *acc, int accID)
{
    QWidget * tab = ui->tabWidget->currentWidget();
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), acc->GetUsername() + " - Common");
    tab->setObjectName(tab->objectName() + "_" + QString::number(accID));

    FillBasicInterface(acc->GetUsername(), acc->GetBalance(), acc->GetHistory(), SLOT(CreateCommonForm()));
}

void Lab08_TNR::CreateSocialForm()
{
    QPushButton * btn = (QPushButton *) sender();
    Form * form = new Form(btn->objectName());
    connect(form, &Form::doneSignal, this, &Lab08_TNR::FinishSocialOperation);
    form->show();
}

void Lab08_TNR::CreateVipForm()
{
    QPushButton * btn = (QPushButton *) sender();
    Form * form = new Form(btn->objectName());
    connect(form, &Form::doneSignal, this, &Lab08_TNR::FinishVipOperation);
    form->show();
}

void Lab08_TNR::CreateCommonForm()
{
    QPushButton * btn = (QPushButton *) sender();
    Form * form = new Form(btn->objectName());
    connect(form, &Form::doneSignal, this, &Lab08_TNR::FinishComOperation);
    form->show();
}

void Lab08_TNR::LogInInterface(QWidget * tab)
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
    connect(button, &QPushButton::pressed, this, &Lab08_TNR::LogIn_pressed);
    button->move(250, 260);
    button->show();
}

void Lab08_TNR::SocialPayment()
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    SocialAccount_TNR * acc = (SocialAccount_TNR *) accounts.at(accID);
    acc->GetSocialPayment();
}

void Lab08_TNR::VipPayment()
{
    int accID = ui->tabWidget->currentWidget()->objectName().section("_", 2, 2).toInt();
    VIPAccount_TNR * acc = (VIPAccount_TNR *) accounts.at(accID);
    acc->GetSocialPayment();
}

void Lab08_TNR::LogIn_pressed()
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
            if (dynamic_cast<SocialAccount_TNR *>(accounts.at(i)) != nullptr) {
                SocialAccount_TNR * acc = (SocialAccount_TNR *)accounts.at(i);
                SocialInterface(acc, i);
            } else if (dynamic_cast<VIPAccount_TNR *>(accounts.at(i)) != nullptr) {
                VIPAccount_TNR * acc = (VIPAccount_TNR *)accounts.at(i);
                VIPInterface(acc, i);
            } else {
                BankAccount_TNR * acc = (BankAccount_TNR *)accounts.at(i);
                CommonInterface(acc, i);
            }
        }

    }
}

void Lab08_TNR::FillBasicInterface(QString username, double accBalance, QList<QString> history, const char *slot)
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

void Lab08_TNR::AddButtonToTab(QString objectName, QString label, const char *slot)
{
    QWidget * tab = ui->tabWidget->currentWidget();
    QPushButton * btn = new QPushButton(label, tab);
    btn->setObjectName(objectName);
    connect(btn, SIGNAL(pressed()), this, slot);
    btn->move(100, curButtonY);
    curButtonY += 40;
    btn->show();
}


void Lab08_TNR::on_print_tnr_pressed()
{
    QListWidget * list = new QListWidget(ui->tabWidget->currentWidget());
    list->move(100, 300);
    for (QString& str : prints) {
        list->addItem(str);
    }
    list->show();
}

