#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QMessageBox>
#include <QShowEvent>


class MessageBox : public QMessageBox
{
int timeout;
bool autoClose;
int currentTime;

public:
void setAutoClose( bool isAuto) {
    autoClose = isAuto;
}
void setTimeout(int time) {
    timeout = time;
}

private:
void showEvent ( QShowEvent * event ) {
    currentTime = 0;
    if (autoClose) {
        this->startTimer(1000);
    }
}

void timerEvent(QTimerEvent *event)
{
    currentTime++;
    if (currentTime>=timeout) {
        this->done(0);
    }
}
};
#endif // MESSAGEBOX_H
