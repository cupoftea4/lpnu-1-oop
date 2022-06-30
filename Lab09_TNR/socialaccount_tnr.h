#ifndef SOCIALACCOUNT_TNR_H
#define SOCIALACCOUNT_TNR_H

#include "bankaccount_tnr.h"
#include <QTimer>

class SocialAccount_TNR : public virtual Account_TNR
{
public:
    SocialAccount_TNR(QString username, std::size_t password);
    SocialAccount_TNR(QString login, QString password);
    virtual bool GetSocialPayment() override;
    bool PayUtilities(double money) override;
    bool WithdrawCash(double money) override;
    virtual QString print() override;

protected:
    void EnableSocialPayment();

};

#endif // SOCIALACCOUNT_TNR_H
