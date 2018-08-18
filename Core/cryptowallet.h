#ifndef CRYPTOWALLET_H
#define CRYPTOWALLET_H

#include "core.h"

#include <QObject>
#include <QVariantMap>
#include <QByteArray>
#include <QString>

class CryptoWallet
{
public:
    CryptoWallet();
    CryptoWallet(QByteArray iData);
    CryptoWallet(QString shortname, QString longname, QString address, QString privateKey, CryptoNetwork iNetwork);
    CryptoWallet(QString shortname, QString longname, QString iSeed, CryptoNetwork iNetwork);

    QString shortname() const;
    QString longname() const;
    bool isMainnet() const;
    QString address() const;
    QString privateKey() const;
    QString confirmedBalance() const;
    QString unconfirmedBalance() const;
    CryptoNetwork network() const;
    bool isValid() const;

    bool isMicroWallet() const;
    QString owner() const;
    QString value() const;

    void setShortname(QString iShortname);
    void setLongname(QString iLongname);
    void setAddress(QString iAddress);
    void setPrivateKey(QString iPrivateKey);
    void setConfirmedBalance(QString iConfirmedBalance);
    void setUnconfirmedBalance(QString iUnconfirmedBalance);
    void setNetwork(CryptoNetwork iNetwork);
    void setIsValid(bool iIsValid);

    void setIsMicroWallet(bool iIsMicro);
    void setOwner(QString iOwner);
    void setValue(QString iValue);

    QByteArray toData() const;

    bool createWallet(QString shortname, QString longname, QString iSeed, CryptoNetwork iNetwork);

private:
    bool createBitcoinWallet(QString iSeed, CryptoNetwork iNetwork);
    bool createLitecoinWallet(QString iSeed, CryptoNetwork iNetwork);
    bool createZCashWallet(QString iSeed, CryptoNetwork iNetwork);
    bool createEthereumWallet(QString iSeed, CryptoNetwork iNetwork);
    bool createDashWallet(QString iSeed, CryptoNetwork iNetwork);

    bool genericCreateWalletFunction(QString iSeed, CryptoNetwork iNetwork);

protected:
    QVariantMap mWalletData;

};

#endif // CRYPTOWALLET_H
