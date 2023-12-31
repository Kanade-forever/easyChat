#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <tcpsocket.h>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onClientReceiveMessageShow(QString message);

    void on_btnImagSelect_clicked();

    void on_btnSendMessage_clicked();


private:
    Ui::Widget *ui;
    tcpSocket tcpsocket;
};
#endif // WIDGET_H
