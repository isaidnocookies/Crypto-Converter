#ifndef DOWNLOADWORKER_H
#define DOWNLOADWORKER_H

#include "core.h"

#include <QMutex>
#include <QObject>
#include <QNetworkAccessManager>
#include <QWaitCondition>

class DownloadWorker : public QObject
{
    Q_OBJECT
public:
    DownloadWorker(QWaitCondition *iWaitCondition, QMutex *iWaitMutex);
    ~DownloadWorker();
signals:
    void finished();
    void error(QString err);
    void marketValueUpdated(QString oShortname, QString oValue);
    void allMarketValuesUpdated(QStringList oNames, QStringList oValues);

public slots:
    void startDownloading();
    void stopDownloading();

private:
    bool                        mDownloading;

    QWaitCondition              *mWaitCondition;
    QMutex                      *mWaitMutex;

    void downloadMarketValues();
};

#endif // DOWNLOADWORKER_H
