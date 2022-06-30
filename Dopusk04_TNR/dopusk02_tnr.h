#ifndef DOPUSK02_TNR_H
#define DOPUSK02_TNR_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Dopusk02_TNR; }
QT_END_NAMESPACE

class Dopusk02_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Dopusk02_TNR(QWidget *parent = nullptr);
    ~Dopusk02_TNR();

private slots:
    void on_pushButton_pressed();

    void on_getBtn_pressed();

    void on_setBtn_pressed();

    void on_closeBtn_pressed();

    void on_pushButton_2_pressed();

    void on_rotateBtn_pressed();

    void on_rotate1Btn_pressed();

private:
    Ui::Dopusk02_TNR *ui;
    QPushButton * buttons[12][12];
    QSize matrixSize;
};
#endif // DOPUSK02_TNR_H
