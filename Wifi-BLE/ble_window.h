#ifndef BLE_WINDOW_H
#define BLE_WINDOW_H

#include <QDialog>

namespace Ui {
class ble_window;
}

class ble_window : public QDialog
{
    Q_OBJECT

public:
    explicit ble_window(QWidget *parent = nullptr);
    ~ble_window();

private:
    Ui::ble_window *ui;
};

#endif // BLE_WINDOW_H
