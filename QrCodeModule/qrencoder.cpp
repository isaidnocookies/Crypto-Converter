#include "qrencoder.h"

#include <iostream>
#include <QPainter>

QImage QrEncoder::createQrCode(QString iInput)
{
    QImage lMyQrCode(400, 400, QImage::Format_RGB32);
    lMyQrCode.fill(Qt::white);

    QPainter lPainter(&lMyQrCode);
    QColor lColor (0, 0, 0, 255);

    const QrCode::Ecc errCorLvl = QrCode::Ecc::HIGH;
    const QrCode qr = QrCode::encodeText(iInput.toStdString().c_str(), errCorLvl);

    const int s = qr.getSize()>0?qr.getSize():1;
    const double w = lMyQrCode.width();
    const double h = lMyQrCode.height();
    const double aspect = w/h;
    const double size = ((aspect>1.0)?h:w);
    const double scale = size/(s+2);

    lPainter.setBrush(lColor);

    for(int y=0; y<s; y++) {
        for(int x=0; x<s; x++) {
            const int color=qr.getModule(x, y);  // 0 for white, 1 for black
            if(0!=color) {
                const double rx1=(x+1)*scale, ry1=(y+1)*scale;
                QRectF r(rx1, ry1, scale, scale);
                lPainter.drawRects(&r,1);
            }
        }
    }

    lPainter.end();
    return lMyQrCode;
}

void QrEncoder::printQrToConsole(const QrCode &iQr)
{
    int border = 4;
    for (int y = -border; y < iQr.getSize() + border; y++) {
        for (int x = -border; x < iQr.getSize() + border; x++) {
            std::cout << (iQr.getModule(x, y) ? "##" : "  ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void QrEncoder::testQrCodeGeneration(QString iInput)
{
    Q_UNUSED(iInput)

    const char *text = "Hello, world!";
    const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;

    // Make and print the QR Code symbol
    const QrCode qr = QrCode::encodeText(text, errCorLvl);
    QrEncoder::printQrToConsole(qr);
//    std::cout << qr.toSvgString(4) << std::endl;
}
