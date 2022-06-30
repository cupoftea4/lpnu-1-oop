#include "toastmessage.h"

ToastMessage::ToastMessage()
{

}

ToastMessage::ToastMessage(QString message)
{
    setText(message);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    setGeometry(750, 500, 250, 200);
    setIcon(QMessageBox::Information);
    setStandardButtons(QMessageBox::NoButton);
    setAutoClose(true);
    setTimeout(1);
    exec();
}
