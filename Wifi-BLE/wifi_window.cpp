#include "wifi_window.h"
#include "ui_wifi_window.h"
#include "wifi_connect.h"
#include "execComm.h"
#include "vector"


wifi_window::wifi_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wifi_window)
{
    ui->setupUi(this);
    QString str;
    str = "WiFi Status: " + QString::fromStdString(execCommand("nmcli radio wifi"));
    ui->label->setText(str);
    ui->label_2->setText("Connected Network: ");
}

wifi_window::~wifi_window()
{
    delete ui;
}

void wifi_window::on_pushButton_2_clicked()
{
    execCommand("nmcli r wifi on");
    QString str = "WiFi Status: " + QString::fromStdString(execCommand("nmcli radio wifi"));
    ui->label->setText(str);
}


void wifi_window::on_pushButton_3_clicked()
{
    execCommand("nmcli r wifi off");
    QString str = "WiFi Status: " + QString::fromStdString(execCommand("nmcli radio wifi"));
    ui->label->setText(str);
}


void wifi_window::on_pushButton_8_clicked()
{
    ui->listWidget->addItem("<----------------------Available Networks---------------------->");
    std::string str = execCommand("nmcli --terse --fields SSID device wifi list");
    wifi_list = parseSSIDs(str);
    for(const auto& ssid: wifi_list){
        ui->listWidget->addItem(QString::fromStdString(ssid));
    }

}


void wifi_window::on_pushButton_4_clicked()
{

    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if(currentItem){
        QString ssid = currentItem->text();
        wifi_connect *newwindow = new wifi_connect(ssid, this);
        newwindow->show();
    }

    std::string name = execCommand("nmcli -t -f name connection show --active");
    QString val = "Connected Network: " + QString::fromStdString(name);
    ui->label_2->setText(val);
}


void wifi_window::on_pushButton_5_clicked()
{
    ui->listWidget->addItem("<----------------------Saved Networks---------------------->");

    std::string str = execCommand("nmcli -t -f name connection show");
    std::vector<std::string> saved;
    saved = parseSSIDs(str);
    for(const auto& ssid: saved){
        ui->listWidget->addItem(QString::fromStdString(ssid));
    }
}


void wifi_window::on_pushButton_6_clicked()
{
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    if(currentItem){
        QString ssid = currentItem->text();
        std::string ss = ssid.toStdString();
        std::string com = "nmcli connection delete \"" + ss + "\"";
        execCommand(com);
    }

}


void wifi_window::on_pushButton_clicked()
{
    std::string name = execCommand("nmcli -t -f name connection show --active");
    QString val = "Connected Network: " + QString::fromStdString(name);
    ui->label_2->setText(val);
}

