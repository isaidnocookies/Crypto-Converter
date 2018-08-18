#ifndef QRREADER_H
#define QRREADER_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QScopedPointer>
#include <QZXing>

#include "QZXing.h"
#include "cameraframegrabber.h"

namespace Ui {
class QrReader;
}

class QrReader : public QWidget
{
    Q_OBJECT

public:
    explicit QrReader(QWidget *parent = 0);
    ~QrReader();

public slots:
    void displayAvailableFrame(QImage iFrame);

signals:
    void sendCameraCode(QString oCode);

private slots:
    void setCamera(const QCameraInfo &cameraInfo);
    void getCameraCode(QString oCode);

    void on_closePushButton_pressed();

private:
    Ui::QrReader *ui;
    CameraFrameGrabber *grabber;
    QScopedPointer<QCamera> m_camera;
};

#endif // QRREADER_H
