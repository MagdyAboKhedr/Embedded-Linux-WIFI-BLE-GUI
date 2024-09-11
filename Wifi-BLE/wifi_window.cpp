#include "wifi_window.h"
#include "ui_wifi_window.h"
#include "execComm.h"

wifi_window::wifi_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wifi_window)
{
    ui->setupUi(this);
    QString str;
    str = "WiFi Status: " + QString::fromStdString(execCommand("nmcli radio wifi"));
    ui->label->setText(str);
}

wifi_window::~wifi_window()
{
    delete ui;
}

void wifi_window::on_pushButton_2_clicked()
{
    execCommand("nmcli r wifi on");
    QString str = "WiFi Status: enabled";
    ui->label->setText(str);
}


void wifi_window::on_pushButton_3_clicked()
{
    execCommand("nmcli r wifi off");
    QString str = "WiFi Status: disabled";
    ui->label->setText(str);
}

