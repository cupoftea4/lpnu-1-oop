#ifndef SIGNALEMITTER_H
#define SIGNALEMITTER_H

#include <QObject>
#include <QTimer>

class SignalEmitter : public QObject
{
    Q_OBJECT
public:
    SignalEmitter(QString username);
    ~SignalEmitter();
    void EmitBalanceUpdate(double balance);
    void EmitHistoryUpdate(QString history);
    void EmitCreditUpdate(double credit);
    QTimer * timer = new QTimer();

signals:
    void BalanceUpdatedSignal(QString username, double balance);
    void HistoryUpdatedSignal(QString username, QString history);
    void CreditUpdatedSignal(QString username, double credit);
    void TimeoutSignal();

private slots:
    void Timeout();
private:
    QString user;
};

#endif // SIGNALEMITTER_H
