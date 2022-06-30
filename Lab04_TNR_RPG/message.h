#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

namespace Ui {
class Message;
}

class Message : public QWidget
{
    Q_OBJECT

public:
//    explicit Message(QWidget *parent = nullptr);
    explicit Message(QString msg = "so i guess you died", QWidget *parent = nullptr);

    ~Message();

signals:
    void restartSignal();
    void closeGameSignal();

private slots:
    void Restart();
    void CloseGame();

private:
    Ui::Message *ui;
};

#endif // MESSAGE_H
