#include "imageviewer.h"
#include "ui_imageviewer.h"

ImageViewer::ImageViewer(QFileInfo file, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    fileInfo = file;

    ui->setupUi(this);
    centralWidget()->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(centralWidget(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(CtxMenu(const QPoint&)));

    const QPixmap pix(fileInfo.filePath());
    ui->label->setPixmap(pix);
    setWindowTitle(fileInfo.fileName());
    QImage img(fileInfo.filePath());
    imgW = img.width();
    imgH = img.height();
    initialSize.setWidth(imgW);
    initialSize.setHeight(imgH);
}

void ImageViewer::CtxMenu(const QPoint& pos){
    QPoint globalPos = centralWidget()->mapToGlobal(pos);

    QMenu myMenu;

    myMenu.addAction("Zoom in", this, SLOT(ZoomIn()));
    myMenu.addAction("Zoom out", this, SLOT(ZoomOut()));
    myMenu.addAction("Zoom 100%", this, SLOT(ZoomInitial()));

    myMenu.exec(globalPos);
}


void ImageViewer::ZoomIn()
{
    ui->label->setPixmap(ui->label->pixmap().scaled(imgW+=100, imgH+=100, Qt::KeepAspectRatio));
}
void ImageViewer::ZoomOut()
{
    ui->label->setPixmap(ui->label->pixmap().scaled(imgW-=100, imgH-=100, Qt::KeepAspectRatio));
}

void ImageViewer::ZoomInitial()
{
    imgH = initialSize.height();
    imgW = initialSize.width();
    ui->label->setPixmap(ui->label->pixmap().scaled(imgW, imgH, Qt::KeepAspectRatio));

}

void ImageViewer::on_actionOpen_image_triggered()
{
    const QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                  ".", tr("JPEG (*.jpg *jpeg)\n"
                                    "GIF (*.gif)\n"
                                    "PNG (*.png)\n"));
    const QFileInfo info(file);
    fileInfo = info;
    const QString fileName(info.fileName());
    const QPixmap pix(file);
    QLabel * label = ui->label;
    label->setPixmap(pix);
    setWindowTitle(fileName);
}


void ImageViewer::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("This is Image Viewer. Made by Amy. \n @cupoftea4");
    msgBox.exec();
}


void ImageViewer::on_actionExit_triggered()
{
    close();
}


void ImageViewer::on_actionSave_As_triggered()
{
    QString newFilePath = QFileDialog::getSaveFileName(this, "Save As", "E:/Desktop/newImage.jpg");
    QFile file(newFilePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Can't save file: " + file.errorString());
        return;
    }
    QImage oldImage(fileInfo.filePath());
    QFileInfo newFileInfo(newFilePath);
    oldImage.save(newFilePath);
    fileInfo = newFileInfo;
    setWindowTitle(fileInfo.fileName());
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

