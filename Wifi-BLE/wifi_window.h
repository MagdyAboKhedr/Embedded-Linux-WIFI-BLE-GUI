#ifndef WIFI_WINDOW_H
#define WIFI_WINDOW_H

#include <QDialog>
#include <vector>
#include <QTimer>

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

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::wifi_window *ui;
    std::vector<std::string> wifi_list;

};

#endif // WIFI_WINDOW_H
