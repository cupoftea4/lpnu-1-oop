#include "notepad.h"
#include "ui_notepad.h"
#include <QFileDialog>
#include <QAction>
#include <QMessageBox>

bool saved;

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
//    connect(ui->actionNewFile, SIGNAL(triggered()), this, SLOT(NewFile()));
    NewFile();
    ui->setupUi(this);
    this->setCentralWidget(ui->NotepadEdit);
}

void Notepad::on_actionSave_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      qDebug() << "Yes was clicked";
      QApplication::quit();
    } else {
      qDebug() << "Yes was *not* clicked";
    }
}

void Notepad::SaveFile() {

}

void Notepad::OpenFile() {

}

void Notepad::NewFile() {
//    QMessageBox::StandardButton reply;
//    reply = QMessageBox::question(this, "Test", "Quit?",
//                                  QMessageBox::Yes|QMessageBox::No);
//    if (reply == QMessageBox::Yes) {
//      qDebug() << "Yes was clicked";
//      QApplication::quit();
//    } else {
//      qDebug() << "Yes was *not* clicked";
//    }
//    qDebug() << ui->menubar->findChild();
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNewFile_triggered()
{
    curFile.clear();
    ui->NotepadEdit->setText(curFile);
    if (ui->NotepadEdit->toPlainText() != "") {

    }
}


void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    curFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can't open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->NotepadEdit->setText(text);
    file.close();
}


void Notepad::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can't save file: " + file.errorString());
        return;
    }
    curFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->NotepadEdit->toPlainText();
    out << text;
    file.close();

}


void Notepad::on_actionPrint_triggered()
{
        QPrinter printer;
        printer.setPrinterName("Printer Name");
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }
        ui->NotepadEdit->print(&printer);
}


void Notepad::on_actionCopy_triggered()
{
    ui->NotepadEdit->copy();
}

void Notepad::on_actionPaste_triggered()
{
    ui->NotepadEdit->paste();
}

void Notepad::on_actionCut_triggered()
{
    ui->NotepadEdit->cut();
}

void Notepad::on_actionUndo_triggered()
{
    ui->NotepadEdit->undo();
}

