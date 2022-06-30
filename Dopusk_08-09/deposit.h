#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "string.h"
#include <chrono>
#include <ctime>
#include <iostream>

typedef std::chrono::system_clock Clock;
#define SIZE 100

class Deposit
{
public:
    Deposit();
    virtual ~Deposit();
    Deposit(char * name, double startingBalance, int totalMonths);

    virtual void GetProfit() = 0;
    virtual void UpdateProfile(char * name, char * password);
protected:
    double balance = 0;
    double startBalance = 0;
    double Percent = 0.1;
    char * name = new char[SIZE];
    char password[SIZE];
    int months = 0;
    std::time_t startDate;
};

#endif // DEPOSIT_H
