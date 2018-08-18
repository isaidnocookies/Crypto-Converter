#include "qrreader.h"
#include "ui_qrreader.h"

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QAbstractVideoSurface>
#include <QCameraInfo>
#include <QMediaMetaData>

#include <QMessageBox>
#include <QPalette>
#include <QPixmap>

QrReader::QrReader(QWidget *parent) :
    ui(new Ui::QrReader)
{
    ui->setupUi(this);
    ui->imageLabel->setAutoFillBackground(true);

    grabber = new CameraFrameGrabber;

    connect(grabber, &CameraFrameGrabber::sendCode, this, &QrReader::getCameraCode);
    setCamera(QCameraInfo::defaultCamera());
}

QrReader::~QrReader()
{
    delete ui;
}

void QrReader::displayAvailableFrame(QImage frame)
{
    ui->imageLabel->setPixmap(QPixmap::fromImage(frame));
}

void QrReader::setCamera(const QCameraInfo &cameraInfo)
{
    m_camera.reset(new QCamera(cameraInfo));

    connect(grabber, &CameraFrameGrabber::frameAvailable, this, &QrReader::displayAvailableFrame);
    m_camera->setViewfinder(grabber);
    m_camera->start();
}

void QrReader::getCameraCode(QString oCode)
{
    emit sendCameraCode(oCode);
    this->hide();
    this->deleteLater();
}

void QrReader::on_closePushButton_pressed()
{
    this->hide();
    this->deleteLater();
}
