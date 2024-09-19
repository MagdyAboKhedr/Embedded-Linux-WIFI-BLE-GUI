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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ble_window *ui;
};

#endif // BLE_WINDOW_H
