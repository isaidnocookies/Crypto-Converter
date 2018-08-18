#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T17:28:11
#
#-------------------------------------------------

#QT       += core network websockets

include(Core.pri)
QT       -= gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#linux | macos | ios {
#    INCLUDEPATH += $$PWD/../libbtc/include
#}

#linux {
#    LIBS += $$PWD/../libbtc/.libs/libbtc.a $$PWD/../libbtc/src/secp256k1/.libs/libsecp256k1.a
#}

#macos {
#    LIBS += $$PWD/../MacDeps/libbtc.a $$PWD/../MacDeps/libsecp256k1.a
#}

#ios {
#    LIBS += $$PWD/../iOSDeps/libbtc.a $$PWD/../iOSDeps/libsecp256k1.a
#}

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}

#include($$PWD/../CertLib/CertLib.pri)

#HEADERS += \
#    core.h \
#    qstringmath.h \
#    walletdatacore.h \
#    wallet.h \
#    bitcoinwallet.h \
#    wcpfield.h \
#    wcpmessage.h \
#    wcpconnection.h \
#    wcpserver.h \
#    wcp.h \
#    wallets.h \
#    wcpmessages/wcpmessagecheckownershipofmicrowalletsreply.h \
#    wcpmessages/wcpmessagecheckownershipofmicrowalletsrequest.h \
#    wcpmessages/wcpmessagecompletemicrowalletsreply.h \
#    wcpmessages/wcpmessagecompletemicrowalletsrequest.h \
#    wcpmessages/wcpmessagecreateaccountreply.h \
#    wcpmessages/wcpmessagecreateaccountrequest.h \
#    wcpmessages/wcpmessagecreatemicrowalletpackagereply.h \
#    wcpmessages/wcpmessagecreatemicrowalletpackagerequest.h \
#    wcpmessages/wcpmessagepingreply.h \
#    wcpmessages/wcpmessagepingrequest.h \
#    wcpmessages/wcpmessagereassignmicrowalletsreply.h \
#    wcpmessages/wcpmessagereassignmicrowalletsrequest.h \
#    wcpmessages.h

#SOURCES += \
#    qstringmath.cpp \
#    walletdatacore.cpp \
#    bitcoinwallet.cpp \
#    wcpmessage.cpp \
#    wcpconnection.cpp \
#    wcpserver.cpp \
#    wcpmessages/wcpmessagecheckownershipofmicrowalletsreply.cpp \
#    wcpmessages/wcpmessagecheckownershipofmicrowalletsrequest.cpp \
#    wcpmessages/wcpmessagecompletemicrowalletsreply.cpp \
#    wcpmessages/wcpmessagecompletemicrowalletsrequest.cpp \
#    wcpmessages/wcpmessagecreateaccountreply.cpp \
#    wcpmessages/wcpmessagecreateaccountrequest.cpp \
#    wcpmessages/wcpmessagecreatemicrowalletpackagereply.cpp \
#    wcpmessages/wcpmessagecreatemicrowalletpackagerequest.cpp \
#    wcpmessages/wcpmessagepingreply.cpp \
#    wcpmessages/wcpmessagepingrequest.cpp \
#    wcpmessages/wcpmessagereassignmicrowalletsrequest.cpp \
#    wcpmessages/wcpmessagereassignmicrowalletsreply.cpp

OTHER_FILES += Core.pri
