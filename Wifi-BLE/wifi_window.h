#ifndef WIFI_WINDOW_H
#define WIFI_WINDOW_H

#include <QDialog>

namespace Ui {
class wifi_window;
}

class wifi_window : public QDialog
{
    Q_OBJECT

public:
    explicit wifi_window(QWidget *parent = nullptr);
    ~wifi_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::wifi_window *ui;
};

#endif // WIFI_WINDOW_H
