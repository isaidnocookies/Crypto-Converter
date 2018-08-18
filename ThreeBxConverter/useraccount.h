#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QObject>
#include <QMap>
#include <QThread>
#include <QWaitCondition>
#include <QSettings>

#include "core.h"
#include "downloadworker.h"

class UserAccount : public QObject
{
    Q_OBJECT

public:
    explicit            UserAccount(QObject *parent = nullptr);
    ~UserAccount();

    Q_INVOKABLE QString getMarketValue(QString iShortname, QString iCurrency = "USD");
    Q_INVOKABLE QString getValue(QString iShortname, QString iCurrency = "USD");
    Q_INVOKABLE void setValue(QString iShortname, QString iValueInCurrency);

signals:
    void marketValueChanged();
    void valueChanged();

public slots:
    void marketValuesUpdated(QStringList iNames, QStringList iValues);
    void downloaderErrorString(QString iError);

private:
    double mValue;

    QWaitCondition *mDownloaderWaitCondition;
    QMutex *mDownloaderMutex;

    QMap<QString, QString> mMarketValues;

    QThread *mMyDownloaderThread;
    DownloadWorker *mMyDownloaderWorker;

    QSettings mSettings;
};

#endif // USERACCOUNT_H
