#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");

    connect(&tcpserver,&tcpServer::serverMessageUpdate,
            this,&Widget::onServerStatusUpdate);
    connect(&tcpserver,&tcpServer::serverReceiveMessageShow,
            this,&Widget::onServerReceiveMessageShow);

    tcpserver.runTcpServer();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onServerStatusUpdate(QString message)
{
    this->ui->textBrowserShowServerStatus->append(message);
}

void Widget::onServerReceiveMessageShow(QString message)
{
    this->ui->textBrowserMessageShow->append("[Client]" + message);
}

void Widget::on_btnMessageSend_clicked()
{
    tcpserver.messageSend(this->ui->textEditMessageInput->toPlainText());
    this->ui->textBrowserMessageShow->append("[Server]" + this->ui->textEditMessageInput->toPlainText());
}

