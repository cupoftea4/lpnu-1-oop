#ifndef DOPUSK03_TNR_H
#define DOPUSK03_TNR_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Dopusk03_TNR; }
QT_END_NAMESPACE

class Dopusk03_TNR : public QMainWindow
{
    Q_OBJECT

public:
    Dopusk03_TNR(QWidget *parent = nullptr);
    ~Dopusk03_TNR();

private slots:
    void on_actionEdit_triggered();

    void on_actionKeep_triggered();

    void on_action_Undo_triggered();

    void on_action_About_triggered();

    void on_action_Exit_triggered();

    void on_action_Redo_triggered();

    void CtxMenu(const QPoint& pos);
        void Edit();
        void Keep();
        void Undo();
        void Redo();

private:
    Ui::Dopusk03_TNR *ui;
    void keyPressEvent(QKeyEvent *event);
    QString undoLineEditText = "";
    QString redoLineEditText = "";
};
#endif // DOPUSK03_TNR_H
