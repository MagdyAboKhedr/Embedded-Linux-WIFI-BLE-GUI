#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    wifi_window wifi;
    wifi.setModal(true);
    wifi.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    ble_window ble;
    ble.setModal(true);
    ble.exec();
}

