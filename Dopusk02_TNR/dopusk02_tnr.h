#ifndef DOPUSK02_TNR_H
#define DOPUSK02_TNR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Dopusk02_TNR; }
QT_END_NAMESPACE

class Dopusk02_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Dopusk02_TNR(QWidget *parent = nullptr);
    ~Dopusk02_TNR();

private:
    Ui::Dopusk02_TNR *ui;
    void onClick(QString buttonName, const char* slot);

public slots:
    void customMenuRequested(QPoint pos);

private slots:
    void EditPressed();
    void SetLabel();
    void Close();
};
#endif // DOPUSK02_TNR_H
