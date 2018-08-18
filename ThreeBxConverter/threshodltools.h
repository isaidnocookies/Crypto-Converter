#ifndef THRESHODLTOOLS_H
#define THRESHODLTOOLS_H

#include <QObject>

#include "core.h"

class ThreshodlTools : public QObject
{
    Q_OBJECT
public:
    explicit ThreshodlTools(QObject *parent = nullptr);

    Q_INVOKABLE QString stringAdd(QString iOne, QString iTwo);
    Q_INVOKABLE void copyToClipboard(QString iDataToCopy);
    Q_INVOKABLE QString getClipboardText();
    Q_INVOKABLE QString formatMarketValueString(QString iInputValue);
};

#endif // THRESHODLTOOLS_H
