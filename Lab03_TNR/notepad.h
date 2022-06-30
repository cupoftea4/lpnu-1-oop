#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTableView>
#include <QKeyEvent>
#include <QTextBlock>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

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
    bool isSaved = false;
    bool handleIsSaved();
    void savedMessageBox();
    void saveTo(QString filePath);
    void onClick(QString buttonName, const char* slot);
    void keyPressEvent(QKeyEvent *event);
//    void closeEvent(QCloseEvent *event);

private slots:
    void OnNotepadTextEdit();

    void on_actionNewFile_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionOpen_triggered();
    void on_actionOpen_image_triggered();
    void on_actionPrint_triggered();

    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_FontSizeSpinBox_valueChanged(int arg1);
    void on_FontColorComboBox_currentTextChanged(const QString &arg1);
    void SetTextBold(bool);
    void SetTextItalic(bool);
    void SetTextUnderline(bool);
    void InsertImage();

    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();

    void on_actionAbout_triggered();
    void on_actionExit_triggered();
};
#endif // NOTEPAD_H
