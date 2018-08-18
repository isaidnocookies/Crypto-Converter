#ifndef PLATFORMINFORMATION_H
#define PLATFORMINFORMATION_H

#include <QObject>

class PlatformInformation : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString deviceOS READ deviceOS WRITE setDeviceOS NOTIFY deviceOSChanged)
    Q_PROPERTY(QString deviceModel READ deviceModel WRITE setDeviceModel NOTIFY deviceModelChanged)

public:
    explicit PlatformInformation(QObject *parent = nullptr);

    QString deviceOS();
    QString deviceModel();

    void setDeviceOS(QString iDeviceOS);
    void setDeviceModel(QString iDeviceModel);

    Q_INVOKABLE int getTopAreaCorrection();
    Q_INVOKABLE int getBottomAreaCorrection();

signals:
    void deviceOSChanged();
    void deviceModelChanged();

private:
    QString mDeviceOS;
    QString mDeviceModel;

    bool    mIsIPhoneX;
};

#endif // PLATFORMINFORMATION_H
