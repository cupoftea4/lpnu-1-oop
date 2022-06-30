#ifndef TOASTMESSAGE_H
#define TOASTMESSAGE_H

#include <QMessageBox>

class ToastMessage : public QMessageBox
{
public:
    ToastMessage();
    ToastMessage(QString message) {
        setText(message);
        setWindowFlags( Qt::FramelessWindowHint | Qt::Dialog );
        setGeometry(690, 570, 250, 200);
        setIcon(QMessageBox::Information);
        setStandardButtons(QMessageBox::NoButton);
        setAutoClose(true);
        setTimeout(1);
        exec();
    };
    void setAutoClose( bool isAuto) {
        autoClose = isAuto;
    }
    void setTimeout(int time) {
        timeout = time;
    }

private:
    int timeout;
    bool autoClose;
    int currentTime;
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

#endif // TOASTMESSAGE_H
