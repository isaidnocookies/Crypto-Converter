#include <QCoreApplication>
#include <QDebug>

#include "qstringmath.h"

void test1();
void test2();
void test3();
void test4();
void test5();

int main(int argc, char *argv[])
{
    Q_UNUSED (argc)
    Q_UNUSED (argv)

    test5();
}

void test1() {
    qDebug() << "\n\n" << "Test1 - Add Strings\n";
    QString lValue1 = "987659.98764567";
    QString lValue2 = "0.098765439801";

    QStringMath lV1 (lValue1);

    qDebug() << lValue1 << " + " << lValue2 << "  =  " << (lV1 + lValue2).toString();
}

void test2() {
    qDebug() << "\n\n" << "Test2 - Standardize Strings\n";
    QString lValue1 = "0.111000";
    QString lValue2 = "1000.987";

    QString lValue1s;
    QString lValue2s;

//    QStringMath::standardizeStrings(lValue1, lValue2, lValue1s, lValue2s);

    qDebug() << lValue1s << "       " << lValue2s;
}

void test3() {
    qDebug() << "\n\n" << "Test3 - Subtract Strings\n";
    QString lValue1 = "10.17";
    QString lValue2 = "1.09";

    QStringMath lV1 (lValue1);

    qDebug() << lValue1 << " - " << lValue2 << "  =  " << (lV1 - lValue2).toString();
}

void test4() {
    qDebug() << "\n\n" << "Test4 - Round to nearest 0.0001\n";
    QString lValue1 = "10.00012";
    QString lValue2 = "1";
    QString lValue3 = "0.00015999";

    qDebug() << lValue1 << " ---> " << QStringMath::roundUpToNearest0001(lValue1).toString();
    qDebug() << lValue2 << " ---> " << QStringMath::roundUpToNearest0001(lValue2).toString();
    qDebug() << lValue3 << " ---> " << QStringMath::roundUpToNearest0001(lValue3).toString();
}

void test5() {
    qDebug() << "\n\n" << "Test 5 - IsMultpleOf\n";
    QString lTest1 = "10.0001";
    QString lTest2 = "0.003";
    QString lTest3 = "10";
    QString lTest4 = "0.00001";
    QString lTest5 = "100.1111";
    QString lTest6 = "100.11113";
    QString lTest7 = "100.1111300";

    qDebug() << lTest1 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest1, "0.0001");
    qDebug() << lTest2 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest2, "0.0001");
    qDebug() << lTest3 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest3, "0.0001");
    qDebug() << lTest4 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest4, "0.0001");
    qDebug() << lTest5 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest5, "0.0001");
    qDebug() << lTest6 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest6, "0.0001");
    qDebug() << lTest7 << " is a muliple of 0.0001 --->" << QStringMath::isMultipleOf(lTest7, "0.0001");
}
