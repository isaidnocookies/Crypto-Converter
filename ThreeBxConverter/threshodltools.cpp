#include "threshodltools.h"

#include <QClipboard>
#include <QGuiApplication>
#include <QDebug>

ThreshodlTools::ThreshodlTools(QObject *parent) : QObject(parent){}

QString ThreshodlTools::stringAdd(QString iOne, QString iTwo)
{
    QStringMath lOne (iOne);
    QStringMath lTwo (iTwo);

    return QStringMath(lOne + lTwo).toString();
}

void ThreshodlTools::copyToClipboard(QString iDataToCopy)
{
    QClipboard *lClipboard = QGuiApplication::clipboard();
    lClipboard->setText(iDataToCopy);
    qDebug() << "Text copied";
}

QString ThreshodlTools::getClipboardText()
{
    QClipboard *lClipboard = QGuiApplication::clipboard();
    qDebug() << "Text returned from clipboard";
    return lClipboard->text();
}

QString ThreshodlTools::formatMarketValueString(QString iInputValue)
{
    QString oValue = iInputValue;
    int lIndexOfDot;

    if (iInputValue.contains(".")) {

        while (oValue.at(oValue.length()-1) == "0") {
            oValue = oValue.remove(oValue.length() - 1, 1);
        }

    } else {
        if (iInputValue == "") {
            oValue = "0.00";
        }
        oValue = iInputValue.append(".00");
    }

    lIndexOfDot = oValue.indexOf(".");
    while (lIndexOfDot > 3) {
        oValue = oValue.insert(lIndexOfDot - 3, ",");
        lIndexOfDot -= 3;
    }

    lIndexOfDot = oValue.indexOf(".");
    while (oValue.size() - lIndexOfDot <= 2) {
        oValue = oValue.append("0");
    }

    return oValue;
}
