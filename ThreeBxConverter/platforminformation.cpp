#include "platforminformation.h"

#include <QSysInfo>

PlatformInformation::PlatformInformation(QObject *parent) : QObject(parent)
{
    // Get platform information
    QString iModelInformation;
    QString iOSInformation = QSysInfo::productType();

    if (iOSInformation == "ios" || iOSInformation == "darwin") {
        mIsIPhoneX = true;
    } else {
        mIsIPhoneX = false;
    }
}

QString PlatformInformation::deviceOS()
{
    return mDeviceOS;
}

QString PlatformInformation::deviceModel()
{
    return mDeviceModel;
}

void PlatformInformation::setDeviceOS(QString iDeviceOS)
{
    if (mDeviceOS == iDeviceOS) {
        return;
    }

    mDeviceOS = iDeviceOS;
    emit deviceOSChanged();
}

void PlatformInformation::setDeviceModel(QString iDeviceModel)
{
    if (mDeviceModel == iDeviceModel) {
        return;
    }

    mDeviceModel = iDeviceModel;
    emit deviceModelChanged();
}

int PlatformInformation::getTopAreaCorrection()
{
    if (mIsIPhoneX) {
        return 50;
    }
    return 20;
}

int PlatformInformation::getBottomAreaCorrection()
{
    if (mIsIPhoneX) {
        return 25;
    }
    return 20;
}
