#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qrencoder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage lQrCode = QrEncoder::createQrCode("Testing this shit");
    ui->qrLabel->setPixmap(QPixmap::fromImage(lQrCode));
}

MainWindow::~MainWindow()
{
    delete ui;
}
