!contains( WALLETMODULES, QSTRINGMATH ) {
    WALLETMODULES += QSTRINGMATH

    INCLUDEPATH += $$PWD

    HEADERS += \
        $$PWD/qstringmath.h

    SOURCES += \
        $$PWD/qstringmath.cpp
}
