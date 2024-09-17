#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H

#include <QDialog>

namespace Ui {
class wifi_connect;
}

class wifi_connect : public QDialog
{
    Q_OBJECT

public:
    explicit wifi_connect(const QString& itemText, QWidget *parent = nullptr);
    ~wifi_connect();

private slots:
    void on_pushButton_clicked();

private:
    Ui::wifi_connect *ui;
    QString itemText_;
};

#endif // WIFI_CONNECT_H
