#include "capture.h"
#include "ui_capture.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include<QMenu>
#include <QAction>
#include<QFileDialog>
capture::capture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capture)
{
    ui->setupUi(this);
    QPixmap pix("A:/qt/gestionmateriaux/resources/template.png");
    int w =ui->pic->width();
    int h =ui->pic->height();
    ui->pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    mCamera = new QCamera(this);
        mCameraViewfinder =new QCameraViewfinder(this);
        mCameraImageCapture = new QCameraImageCapture(mCamera, this);
        mLayout = new QVBoxLayout;
        mOptionMenu = new QMenu("Options", this );
        mEncenderAction =new QAction ("ouvrir cam",this);
        mApagarAction = new QAction ("fermer cam",this);
        mCapturarAction =new QAction ("afaire une capture",this);
        mOptionMenu->addActions({mEncenderAction,mApagarAction,mCapturarAction});
        ui->option_pushButton->setMenu(mOptionMenu);
        mCamera->setViewfinder(mCameraViewfinder);
        mLayout->addWidget(mCameraViewfinder);
        mLayout->setMargin(0);
        ui->scrollArea->setLayout(mLayout);

        connect(mEncenderAction,&QAction::triggered,[&] (){
            mCamera->start();


        });

        connect(mApagarAction,&QAction::triggered, [&](){
            mCamera->stop();
            mCamera->destroyed(this);

        });

        connect(mCapturarAction,&QAction::triggered,[&](){
             mCamera->start();
           auto filename=  QFileDialog::getSaveFileName(this,"capture","/", "Imagen (*.jpg;*.jpeg)");
        if(filename.isEmpty())
        {return ;}
           mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings ;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
        });
}

capture::~capture()
{
    delete ui;
}
