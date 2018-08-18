#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include <QZXing.h>

#include "platforminformation.h"
#include "threshodltools.h"
#include "useraccount.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    #ifdef Q_OS_MAC
        app.setWindowIcon(QIcon("/macx/threshodlX_icon_mac.png.icns"));
    #endif

    qmlRegisterType<PlatformInformation>("com.threeb.ThreeBxConverter.PlatformInformation", 1, 0, "PlatformInformation");
    qmlRegisterType<ThreshodlTools>("com.threeb.ThreeBxConverter.ThreshodlTools", 1, 0, "ThreshodlTools");
    qmlRegisterType<UserAccount>("com.threeb.ThreeBxConverter.UserAccount", 1, 0, "UserAccount");

    QQmlApplicationEngine engine;

    QZXing::registerQMLTypes();
    QZXing::registerQMLImageProvider(engine);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
