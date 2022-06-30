#include "signalemitter.h"

SignalEmitter::SignalEmitter(QString username)
{
    this->user = username;
    QObject::connect(timer, &QTimer::timeout, this, &SignalEmitter::Timeout);
}

SignalEmitter::~SignalEmitter()
{
    delete timer;
}

void SignalEmitter::EmitBalanceUpdate(double balance)
{
    emit BalanceUpdatedSignal(user, balance);
}

void SignalEmitter::EmitHistoryUpdate(QString history)
{
    emit HistoryUpdatedSignal(user, history);
}

void SignalEmitter::EmitCreditUpdate(double credit)
{
    emit CreditUpdatedSignal(user, credit);
}

void SignalEmitter::Timeout()
{
    emit TimeoutSignal();
}
