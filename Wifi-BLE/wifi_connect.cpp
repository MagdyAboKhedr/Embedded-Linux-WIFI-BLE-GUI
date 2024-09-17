#include "wifi_connect.h"
#include "ui_wifi_connect.h"
#include "execComm.h"
#include <QDebug>
#include <iostream>

wifi_connect::wifi_connect(const QString& itemText, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wifi_connect)
    , itemText_(itemText)
{
    ui->setupUi(this);

}

wifi_connect::~wifi_connect()
{
    delete ui;
}

void wifi_connect::on_pushButton_clicked()
{
    QString pw = ui->lineEdit->text();
    QString full = QString("nmcli device wifi connect \"%1\" password \"%2\" && echo \"a\" || echo \"b\"" ).arg(itemText_).arg(pw);
    std::string str = full.QString::toStdString();
    std::string confirm = execCommand(str);


}

