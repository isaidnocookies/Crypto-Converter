#include "downloadworker.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QJsonDocument>

DownloadWorker::DownloadWorker(QWaitCondition *iWaitCondition, QMutex *iWaitMutex)
{
    mWaitCondition = iWaitCondition;
    mWaitMutex = iWaitMutex;
}

DownloadWorker::~DownloadWorker()
{
    mDownloading = false;
}

void DownloadWorker::startDownloading()
{
    mDownloading = true;
    QThread::sleep(5);
    qDebug() << "Downloader Started...";

    while (mDownloading) {
        downloadMarketValues();
        QThread::sleep(POLLING_INTERVAL);
    }

    emit finished();
}

void DownloadWorker::stopDownloading()
{
    mDownloading = false;
}

void DownloadWorker::downloadMarketValues()
{
    QNetworkAccessManager   *mNetworkManager = new QNetworkAccessManager(this);
    QEventLoop              lMyEventLoop;
    QNetworkReply           *lReply;
    connect(mNetworkManager, SIGNAL(finished(QNetworkReply*)), &lMyEventLoop, SLOT(quit()));

    //https://_pyts.threebx.com/ex/rates
    auto lRequestURL = QUrl(QString("%1/%2").arg(TASK_SERVER_URL).arg("ex/rates"));
    qDebug() << lRequestURL;

    lReply = mNetworkManager->get(QNetworkRequest(lRequestURL));
    lMyEventLoop.exec();

    if (lReply->error() == QNetworkReply::NoError) {
        QByteArray      lReplyText = lReply->readAll();
        auto            lMyMap = QJsonDocument::fromJson(lReplyText).toVariant().toMap();
        QMap<QString, QString> lUpdatedValues;
        QStringList lNames, lValues;

        for (auto coin : AppWallets::walletNames().keys()) {
            lNames.append(coin);
            lValues.append(lMyMap[(coin.at(0) == "t" ? coin.remove(0, 1) : coin)].toMap()["USD"].toMap()["rate"].toString());
        }
        emit allMarketValuesUpdated(lNames, lValues);
    } else {
        qDebug() << "Error.... Can not update market values...";
    }
}
