#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class ImageViewer;
}

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QFileInfo file, QWidget *parent = nullptr);
    ~ImageViewer();

private:
    Ui::ImageViewer *ui;
    QFileInfo fileInfo;
    int imgW;
    int imgH;
    QSize initialSize;

private slots:
    void on_actionSave_As_triggered();
    void on_actionOpen_image_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

    void CtxMenu(const QPoint& pos);
        void ZoomIn();
        void ZoomOut();
        void ZoomInitial();
};

#endif // IMAGEVIEWER_H
