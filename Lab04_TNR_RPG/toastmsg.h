#ifndef TOASTMSG_H
#define TOASTMSG_H

#include <QWidget>

namespace Ui {
class ToastMsg;
}

class ToastMsg : public QWidget
{
    Q_OBJECT

public:
    explicit ToastMsg(QWidget *parent = nullptr);
    explicit ToastMsg(QString message, QWidget *parent = nullptr);
    ~ToastMsg();
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
            this->close();
            delete this;
        }
    }
    Ui::ToastMsg *ui;
};

#endif // TOASTMSG_H
