#include "notepad.h"
#include "ui_notepad.h"
#include "imageviewer.h"
#include "MessageBox.h"
#include "aboutwindow.h"
#include <QStandardPaths>

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    setWindowTitle("*Not saved");
    onClick("BoldButton", SLOT(SetTextBold(bool)));
    onClick("ItalicButton", SLOT(SetTextItalic(bool)));
    onClick("UnderlineButton", SLOT(SetTextUnderline(bool)));
    connect(ui->InsertImgButton, SIGNAL(clicked()), this, SLOT(InsertImage()));

    connect(ui->NotepadEdit, SIGNAL(textChanged()), this, SLOT(OnNotepadTextEdit()));

}

void Notepad::OnNotepadTextEdit()
{
    if(windowTitle()[0] != '*')
    {
        isSaved = false;
        setWindowTitle("*" + windowTitle());
    }

}

bool Notepad::handleIsSaved()
{
    if(!isSaved)
    {
        QMessageBox msg(QMessageBox::Warning, "Notepad", "You have unsaved changes", QMessageBox::Cancel, this, Qt::WindowFlags());
        msg.addButton(QMessageBox::Save);
        msg.addButton(QMessageBox::Discard);

        int answer = msg.exec();
        if(answer == QMessageBox::Save) {
          on_actionSave_triggered();
        } else if (answer == QMessageBox::Cancel) {
          return false;
        }
    }
    return true;
};

void Notepad::on_actionNewFile_triggered()
{
    if(handleIsSaved())
    {
        curFile.clear();
        ui->NotepadEdit->setText(curFile);
        setWindowTitle("*Not saved");
        isSaved = false;
    }

}

void Notepad::savedMessageBox()
{
    MessageBox msgBox;
    msgBox.setText("Saved");
    msgBox.setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    msgBox.setGeometry(750, 500, 250, 200);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::NoButton);
    msgBox.setAutoClose(true);
    msgBox.setTimeout(1);
    msgBox.exec();
}

void Notepad::saveTo(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can't save file: " + file.errorString());
        return;
    }
    QTextStream out(&file);
    QString text = ui->NotepadEdit->toPlainText();
    out << text;
    file.close();
    savedMessageBox();
    if (!isSaved) {
        QString subString = this->windowTitle().right(windowTitle().length()-1);
        setWindowTitle(subString);
        isSaved = true;
    }
}

void Notepad::on_actionSave_triggered()
{
    if(curFile.isEmpty()) {
        on_actionSaveAs_triggered();
        return;
    }
    saveTo(curFile);
}

void Notepad::on_actionSaveAs_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save As", "E:/Desktop/newFile.txt", ".txt");
    saveTo(filePath);
    const QFileInfo info(filePath);
    const QString fileName(info.fileName());
    curFile = filePath;
    setWindowTitle(fileName);
}

void Notepad::on_actionOpen_triggered()
{
        if(handleIsSaved()){
            QString filePath = QFileDialog::getOpenFileName(this, "Open the file");
            QFile file(filePath);
            curFile = filePath;
            if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
                QMessageBox::warning(this, "Warning", "Can't open file: " + file.errorString());
                return;
            }
            const QFileInfo info(filePath);
            const QString fileName(info.fileName());
            qDebug() << fileName;
            QTextStream in(&file);
            QString text = in.readAll();
            ui->NotepadEdit->setText(text);
            file.close();
            isSaved = true;
            setWindowTitle(fileName);
        }

}

void Notepad::on_actionOpen_image_triggered()
{
        const QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                      ".", tr("JPEG (*.jpg *jpeg)\n"
                                        "GIF (*.gif)\n"
                                        "PNG (*.png)\n"));
        const QFileInfo info(file);
        ImageViewer * imageViewer = new ImageViewer(info);
        imageViewer->show();
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

void Notepad::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    QTextCharFormat format;
    format.setFontFamily(f.family());
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    if(cursor.hasSelection()) {
        ui->NotepadEdit->textCursor().mergeCharFormat(format);
    }
}


void Notepad::on_FontSizeSpinBox_valueChanged(int fontSize)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    QTextCharFormat format;
    format.setFontPointSize(fontSize);
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    if(cursor.hasSelection()) {
        ui->NotepadEdit->textCursor().mergeCharFormat(format);
    }
}


void Notepad::on_FontColorComboBox_currentTextChanged(const QString &color)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    if(cursor.hasSelection()) {
        cursor.insertHtml("<span style=\"color:" + color + "\">" + cursor.selectedText());
        cursor.insertHtml("</span>");
    }
}

void Notepad::SetTextBold(bool checked)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat format;
    if (!checked) {
        format.setFontWeight(QFont::Normal);
    } else {
        format.setFontWeight(QFont::Bold);
    }
    ui->NotepadEdit->textCursor().mergeCharFormat(format);

}

void Notepad::SetTextItalic(bool checked)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat format;
    if (!checked) {
        format.setFontItalic(false);
    } else {
        format.setFontItalic(true);
    }
    ui->NotepadEdit->textCursor().mergeCharFormat(format);
}

void Notepad::SetTextUnderline(bool checked)
{
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    QTextCharFormat format;
    if (!checked) {
        format.setFontUnderline(false);
    } else {
        format.setFontUnderline(true);
    }
    ui->NotepadEdit->textCursor().mergeCharFormat(format);
}

void Notepad::InsertImage()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                  ".", tr("JPEG (*.jpg *jpeg)\n"
                                    "GIF (*.gif)\n"
                                    "PNG (*.png)\n"));
    QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
    QImage image(file);

    QTextDocument * textDocument = ui->NotepadEdit->document();
    textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
    QTextCursor cursor = ui->NotepadEdit->textCursor();
    QTextImageFormat imageFormat;
    imageFormat.setWidth( 300 );
    imageFormat.setName( Uri.toString() );
    cursor.insertImage(imageFormat);
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

void Notepad::on_actionAbout_triggered()
{
    AboutWindow * msgBox = new AboutWindow();
//  AboutWindow  msgBox.setText("This is Notepad. Made by Amy. \n @cupoftea4");
    msgBox->show();
}

void Notepad::on_actionExit_triggered()
{
    if(handleIsSaved()) {
        close();
    }
}

//void closeEvent(QCloseEvent *event) {
////    if(handleIsSaved()) {
////        event->accept();
////    } else {
////        event->ignore();
////    }
//}

void Notepad::onClick(QString buttonName, const char* slot)
{
    QPushButton * button = Notepad::findChild<QPushButton *>(buttonName);
    connect(button, SIGNAL(clicked(bool)), this, slot);
    button->setCheckable(true);
}

void Notepad::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Alt)
    {
        QList<QMenu*> menus = ui->menubar->findChildren<QMenu*>();
        menus[0]->setTitle("&File");
        menus[1]->setTitle("&Edit");
        menus[2]->setTitle("&Help");
    }
}

Notepad::~Notepad()
{
    delete ui;
}
