!contains( WALLETMODULES, QRCODE_MODULES ) {
    WALLETMODULES += QRCODE_MODULES

    !contains( QT, core ):              QT += core
    !contains( QT, widgets ):           QT += widgets
    !contains( QT, multimediawidgets ): QT += multimediawidgets
    !contains( QTPLUGIN, qavfcamera ):  QTPLUGIN += qavfcamera

    INCLUDEPATH += $$PWD

    include(QzXing/QZXing.pri)

    SOURCES += \
        $$PWD/Nayuki/BitBuffer.cpp \
        $$PWD/Nayuki/QrCode.cpp \
        $$PWD/Nayuki/QrSegment.cpp \
        $$PWD/qrencoder.cpp

    HEADERS += \
        $$PWD/Nayuki/BitBuffer.hpp \
        $$PWD/Nayuki/QrCode.hpp \
        $$PWD/Nayuki/QrSegment.hpp \
        $$PWD/qrencoder.h
}

FORMS += \
    $$PWD/qrreader.ui

HEADERS += \
    $$PWD/qrreader.h \
    $$PWD/cameraframegrabber.h

SOURCES += \
    $$PWD/qrreader.cpp \
    $$PWD/cameraframegrabber.cpp
