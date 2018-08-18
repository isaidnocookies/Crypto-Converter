#ifndef QRENCODER_H
#define QRENCODER_H

#include <QImage>
#include <QString>

#include "Nayuki/QrCode.hpp"
#include "Nayuki/BitBuffer.hpp"

using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

class QrEncoder
{
public:
    static QImage createQrCode (QString iInput);
    static void printQrToConsole(const QrCode &iQr);
    static void testQrCodeGeneration(QString iInput);

};

#endif // QRENCODER_H
