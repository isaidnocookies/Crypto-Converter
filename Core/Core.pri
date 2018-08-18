!contains( WALLETMODULES, WALLET_CORE ) {
    WALLETMODULES += WALLET_CORE

    !contains( QT, core ):          QT += core
    !contains( QT, network ):       QT += network

    INCLUDEPATH += $$PWD

    HEADERS += \
        $$PWD/core.h \
        $$PWD/qstringmath.h \
        $$PWD/globalsAndConstants.h

    SOURCES += \
        $$PWD/qstringmath.cpp
}
