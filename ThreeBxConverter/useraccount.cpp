#include "useraccount.h"

#include <QDebug>

UserAccount::UserAccount(QObject *parent) : QObject(parent)
{
    mDownloaderWaitCondition = new QWaitCondition;
    mDownloaderMutex = new QMutex;

    mMyDownloaderThread = new QThread;
    mMyDownloaderWorker = new DownloadWorker(mDownloaderWaitCondition, mDownloaderMutex);

    mMyDownloaderWorker->moveToThread(mMyDownloaderThread);

    connect(mMyDownloaderWorker, SIGNAL (error(QString)), this, SLOT (downloaderErrorString(QString)));
    connect(mMyDownloaderThread, SIGNAL (started()), mMyDownloaderWorker, SLOT (startDownloading()));
    connect(mMyDownloaderWorker, SIGNAL (finished()), mMyDownloaderThread, SLOT (quit()));
    connect(mMyDownloaderWorker, SIGNAL (finished()), mMyDownloaderWorker, SLOT (deleteLater()));
    connect(mMyDownloaderThread, SIGNAL (finished()), mMyDownloaderThread, SLOT (deleteLater()));

    connect(mMyDownloaderWorker, &DownloadWorker::allMarketValuesUpdated, this, &UserAccount::marketValuesUpdated);

    if (mSettings.contains(DataKeys::marketValueDataKey())) {
        mMarketValues.clear();
        auto lMap = mSettings.value(DataKeys::marketValueDataKey()).toMap();

        for (auto key : lMap.keys()) {
            mMarketValues.insert(key, lMap[key].toString());
        }
    }

    mMyDownloaderThread->start();
    mValue = 0;
}

UserAccount::~UserAccount()
{

}

QString UserAccount::getMarketValue(QString iShortname, QString iCurrency)
{
    Q_UNUSED(iCurrency)

    return mMarketValues[iShortname];
}

QString UserAccount::getValue(QString iShortname, QString iCurrency)
{
    Q_UNUSED(iCurrency)

    QString lValueToReturn;

    if (iShortname == "USD") {
        lValueToReturn = QString::number(mValue);
    } else {
        double lMarketValue = mMarketValues[iShortname].toDouble();
        lValueToReturn = QString::number(mValue / lMarketValue);
    }

    return lValueToReturn;
}

void UserAccount::setValue(QString iShortname, QString iValue)
{
    QString lValue = iValue;

    if (lValue.count(".") > 1) {
        return;
    }

    while (lValue.contains(",")) {
        lValue = lValue.remove(",");
    }

    if (iShortname == "USD") {
        if (lValue.contains("$")) {
            mValue = lValue.remove("$").toDouble();
        } else {
            mValue = lValue.toDouble();
        }
    } else {
        mValue = lValue.toDouble() * mMarketValues[iShortname].toDouble();
    }

    emit valueChanged();
}

void UserAccount::marketValuesUpdated(QStringList iNames, QStringList iValues)
{
    QVariantMap lSettingsMap;

    for (int i = 0; i < iNames.size(); i++) {
        qDebug() << iNames.at(i) << " --- " << iValues.at(i);
        mMarketValues[iNames.at(i)] = iValues.at(i);
        lSettingsMap.insert(iNames.at(i), iValues.at(i));
    }

    mSettings.setValue(DataKeys::marketValueDataKey(), lSettingsMap);
    mSettings.sync();

    emit marketValueChanged();
}

void UserAccount::downloaderErrorString(QString iError)
{
    qDebug() << "Error from downloader:  " << iError;
}
