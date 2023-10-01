#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <tcpserver.h>
#include <QLineEdit>
#include <QThread>
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

private:
    Ui::Widget *ui;
    tcpServer tcpserver;

private slots:
    void onServerStatusUpdate(QString message);
    void onServerReceiveMessageShow(QString message);
    void on_btnMessageSend_clicked();
    void on_btnImagSelect_clicked();
};
#endif // WIDGET_H
