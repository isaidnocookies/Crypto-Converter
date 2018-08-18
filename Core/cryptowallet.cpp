#include "cryptowallet.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

CryptoWallet::CryptoWallet()
{
    setIsValid(false);
}

CryptoWallet::CryptoWallet(QByteArray iData)
{
    QJsonParseError lError;
    mWalletData = QJsonDocument::fromJson(iData, &lError).toVariant().toMap();

    if (lError.error != QJsonParseError::NoError) {
        mWalletData.clear();
        setIsValid(false);
    } else {
        setIsValid(true);
    }
}

CryptoWallet::CryptoWallet(QString shortname, QString longname, QString address, QString privateKey, CryptoNetwork iNetwork)
{
    setShortname(shortname);
    setLongname(longname);
    setAddress(address);
    setPrivateKey(privateKey);
    setNetwork(iNetwork);
    setIsValid(true);
}

CryptoWallet::CryptoWallet(QString shortname, QString longname, QString iSeed, CryptoNetwork iNetwork)
{
    setShortname(shortname);
    setLongname(longname);
    setNetwork(iNetwork);

    if (createWallet(shortname, longname, iSeed, iNetwork)) {
        setIsValid(true);
    } else {
        mWalletData.clear();
        setIsValid(false);
    }
}

QString CryptoWallet::shortname() const
{
    QString key = "shortname";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

QString CryptoWallet::longname() const
{
    QString key = "longname";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

bool CryptoWallet::isMainnet() const
{
    if (mWalletData["network"].toInt() == static_cast<int>(CryptoNetwork::Main)) {
        return true;
    } else {
        return false;
    }
}

QString CryptoWallet::address() const
{
    QString key = "address";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

QString CryptoWallet::privateKey() const
{
    QString key = "privateKey";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

QString CryptoWallet::confirmedBalance() const
{
    QString key = "confirmedBalance";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

QString CryptoWallet::unconfirmedBalance() const
{
    QString key = "unconfirmedBalance";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

CryptoNetwork CryptoWallet::network() const
{
    QString key = "network";
    if (mWalletData.contains(key)) {
        return static_cast<CryptoNetwork>(mWalletData[key].toInt());
    }
    return CryptoNetwork::None;
}

bool CryptoWallet::isValid() const
{
    QString key = "isValid";
    if (mWalletData.contains(key)) {
        return (mWalletData[key].toBool());
    }
    return false;
}

bool CryptoWallet::isMicroWallet() const
{
    QString key = "isMicroWallet";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toBool();
    }
    return false;
}

QString CryptoWallet::owner() const
{
    QString key = "owner";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

QString CryptoWallet::value() const
{
    QString key = "value";
    if (mWalletData.contains(key)) {
        return mWalletData[key].toString();
    }
    return QString();
}

void CryptoWallet::setShortname(QString iShortname)
{
    QString key = "shortname";
    mWalletData[key] = iShortname;
}

void CryptoWallet::setLongname(QString iLongname)
{
    QString key = "longname";
    mWalletData[key] = iLongname;
}

void CryptoWallet::setAddress(QString iAddress)
{
    QString key = "address";
    mWalletData[key] = iAddress;
}

void CryptoWallet::setPrivateKey(QString iPrivateKey)
{
    QString key = "privateKey";
    mWalletData[key] = iPrivateKey;
}

void CryptoWallet::setConfirmedBalance(QString iConfirmedBalance)
{
    QString key = "confirmedBalance";
    mWalletData[key] = iConfirmedBalance;
}

void CryptoWallet::setUnconfirmedBalance(QString iUnconfirmedBalance)
{
    QString key = "unconfirmedBalance";
    mWalletData[key] = iUnconfirmedBalance;
}

void CryptoWallet::setNetwork(CryptoNetwork iNetwork)
{
    QString key = "network";
    mWalletData[key] = iNetwork;
}

void CryptoWallet::setIsValid(bool iIsValid)
{
    QString key = "isValid";
    mWalletData[key] = iIsValid;
}

void CryptoWallet::setIsMicroWallet(bool iIsMicro)
{
    QString key = "isMicroWallet";
    mWalletData[key] = iIsMicro;
}

void CryptoWallet::setOwner(QString iOwner)
{
    QString key = "owner";
    mWalletData[key] = iOwner;
}

void CryptoWallet::setValue(QString iValue)
{
    QString key = "value";
    mWalletData[key] = iValue;
}

QByteArray CryptoWallet::toData() const
{
    return QJsonDocument::fromVariant(mWalletData).toJson(QJsonDocument::Compact);
}

bool CryptoWallet::createWallet(QString shortname, QString longname, QString iSeed, CryptoNetwork iNetwork)
{
    CryptoNetwork lNetwork = iNetwork;
    if (shortname.at(0) == "t") {
        lNetwork = CryptoNetwork::TestNet;
    }

    if (shortname == "BTC") {
        return createBitcoinWallet(iSeed, lNetwork);
    } else if (shortname == "tBTC") {
        return createBitcoinWallet(iSeed, lNetwork);
    } else if (shortname == "ZEC") {
        return createZCashWallet(iSeed, lNetwork);
    } else if (shortname == "tZEC") {
        return createZCashWallet(iSeed, lNetwork);
    } else if (shortname == "DASH") {
        return createDashWallet(iSeed, lNetwork);
    } else if (shortname == "tDASH") {
        return createDashWallet(iSeed, lNetwork);
    } else if (shortname == "LTC") {
        return createLitecoinWallet(iSeed, lNetwork);
    } else if (shortname == "tLTC") {
        return createLitecoinWallet(iSeed, lNetwork);
    } else if (shortname == "ETH") {
        return false;
    } else if (shortname == "tETH") {
        return false;
    }

    return false;
}

bool CryptoWallet::createBitcoinWallet(QString iSeed, CryptoNetwork iNetwork)
{
    return genericCreateWalletFunction(iSeed, iNetwork);
}

bool CryptoWallet::createLitecoinWallet(QString iSeed, CryptoNetwork iNetwork)
{
    return genericCreateWalletFunction(iSeed, iNetwork);
}

bool CryptoWallet::createZCashWallet(QString iSeed, CryptoNetwork iNetwork)
{
    return genericCreateWalletFunction(iSeed, iNetwork);
}

bool CryptoWallet::createEthereumWallet(QString iSeed, CryptoNetwork iNetwork)
{
    return false;
}

bool CryptoWallet::createDashWallet(QString iSeed, CryptoNetwork iNetwork)
{
    return genericCreateWalletFunction(iSeed, iNetwork);
}

bool CryptoWallet::genericCreateWalletFunction(QString iSeed, CryptoNetwork iNetwork)
{
    QString lCoin = shortname();
    if (lCoin.at(0) == "t") {
        lCoin.remove(0, 1);
    }

    QNetworkAccessManager   *mNetworkManager = new QNetworkAccessManager();
    QEventLoop              lMyEventLoop;
    QNetworkReply           *lReply;
    QObject::connect(mNetworkManager, SIGNAL(finished(QNetworkReply*)), &lMyEventLoop, SLOT(quit()));

    QJsonObject jsonData;
    QJsonArray coinArray;

    coinArray.append(lCoin);

    jsonData.insert("coins", coinArray);
    jsonData.insert("seed", iSeed);
    jsonData.insert("network", static_cast<int>(iNetwork));

    QJsonDocument jsonDataDocument;
    jsonDataDocument.setObject(jsonData);

    QByteArray request_body = jsonDataDocument.toJson();
    QUrl lRequestURL = QUrl::fromUserInput(QString(MY_WALLET_SERVER_ADDRESS).append("/wallets/create/"));
    qDebug() << lRequestURL;

    QNetworkRequest lRequest;
    lRequest.setUrl(lRequestURL);
    lRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    lReply = mNetworkManager->post(lRequest, request_body);
    lMyEventLoop.exec();

    if (lReply->error() == QNetworkReply::NoError) {
        QByteArray      lReplyText = lReply->readAll();
        auto            lMyMap = QJsonDocument::fromJson(lReplyText).toVariant().toMap();

        qDebug() << lReplyText;

        if (lMyMap["success"].toBool()) {
            auto lCoinMap = lMyMap["message"].toMap();
            auto lCoinWallet = lCoinMap[lCoin].toMap();

            setAddress(lCoinWallet["address"].toString());
            setIsMicroWallet(false);
            setPrivateKey(lCoinWallet["wif"].toString());
        } else {
            qDebug() << "Error(1).... Failed to create wallet " << shortname();
            return false;
        }
    } else {
        qDebug() << "Error(2).... Failed to create wallet : " << shortname();
        return false;
    }

    return true;
}
