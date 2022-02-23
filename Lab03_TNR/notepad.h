#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private:
    Ui::Notepad *ui;
    QString curFile = "";

private slots:
    void SaveFile();
    void OpenFile();
    void NewFile();

    void on_actionSave_triggered();
    void on_actionNewFile_triggered();
    void on_actionOpen_triggered();
    void on_actionSaveAs_triggered();
    void on_actionPrint_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
};
#endif // NOTEPAD_H
