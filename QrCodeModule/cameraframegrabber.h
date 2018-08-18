#ifndef CAMERAFRAMEGRABBER_H
#define CAMERAFRAMEGRABBER_H

#include <QAbstractVideoSurface>
#include <QList>
#include <QZXing>

#include "QZXing.h"

class CameraFrameGrabber : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit CameraFrameGrabber(QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;
    bool present(const QVideoFrame &frame);

signals:
    void frameAvailable(QImage frame);
    void sendCode(QString oCode);

private:
    QZXing *decoder;
};

#endif // CAMERAFRAMEGRABBER_H
