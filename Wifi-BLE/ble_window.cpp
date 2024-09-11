#include "ble_window.h"
#include "ui_ble_window.h"

ble_window::ble_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ble_window)
{
    ui->setupUi(this);
}

ble_window::~ble_window()
{
    delete ui;
}
