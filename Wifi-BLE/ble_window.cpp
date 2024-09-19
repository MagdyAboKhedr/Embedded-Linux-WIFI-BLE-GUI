#include "ble_window.h"
#include "ui_ble_window.h"
#include "execComm.h"
#include <iostream>
#include <string>
#include <QString>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QDebug>

ble_window::ble_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ble_window)
{
    ui->setupUi(this);
    std::string str = execCommand("bluetoothctl show | grep \"Powered\" | awk '{print $2}'");
    if (str == "yes\n"){
        ui->label->setText("Bluetooth Status: ON");
    }
    else if(str == "no\n") {
        ui->label->setText("Bluetooth Status: OFF");
    }
    else{
        ui->label->setText("??");
    }

}

ble_window::~ble_window()
{
    delete ui;
}

void ble_window::on_pushButton_clicked()
{
    execCommand("bluetoothctl power on");
    ui->label->setText("Bluetooth Status: ON");
}


void ble_window::on_pushButton_2_clicked()
{
    execCommand("bluetoothctl power off");
    ui->label->setText("Bluetooth Status: OFF");
}


void ble_window::on_pushButton_3_clicked()
{
    ui->listWidget->addItem("<----------Scan Started, Press Show Devices-------->");
    QFuture<void> future = QtConcurrent::run([this](){
       execCommand("bluetoothctl scan on");
    });
}


void ble_window::on_pushButton_6_clicked()
{
    ui->listWidget->clear();
    std::vector<std::string> ble_list;
    ui->listWidget->addItem("<----------Devices Available-------->");
    ble_list = parseSSIDs(execCommand("bluetoothctl devices"));
    for(const auto& ssid: ble_list){
        ui->listWidget->addItem(QString::fromStdString(ssid));
    }

}


void ble_window::on_pushButton_7_clicked()
{
    execCommand("bluetoothctl scan off");
}


void ble_window::on_pushButton_4_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if(currentItem){
        QString str = currentItem->text();
        std::string mac = str.toStdString();
        std::string new_mac = extractMACAddress(mac);
        std::string cmd = "bluetoothctl pair " + new_mac;
        execCommand(cmd);

    }


}

