#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");

    connect(&tcpsocket,&tcpSocket::clientReceiveMessageShow,
            this,&Widget::onClientReceiveMessageShow);

    tcpsocket.runTcpSocket();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onClientReceiveMessageShow(QString message)
{
    this->ui->textBrowserMessageShow->append(message);
}

void Widget::on_btnImagSelect_clicked()
{

}


void Widget::on_btnSendMessage_clicked()
{
    tcpsocket.messageSend(this->ui->textEditMessageInput->toPlainText());
    this->ui->textBrowserMessageShow->append("[Client]" + this->ui->textEditMessageInput->toPlainText());
}

