#ifndef CAPTURE_H
#define CAPTURE_H

#include <QDialog>

namespace Ui {
class capture;
}
class QCamera ;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu ;
class QAction ;

class capture : public QDialog
{
    Q_OBJECT

public:
    explicit capture(QWidget *parent = nullptr);
    ~capture();

private:
    Ui::capture *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
     QAction *mCapturarAction ;
};

#endif // CAPTURE_H
