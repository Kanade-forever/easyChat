#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");

    connect(&tcpserver,&tcpServer::serverMessageUpdate,
            this,&Widget::onServerMessageUpdate);

    tcpserver.runTcpServer();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onServerMessageUpdate(QString message)
{
    this->ui->textBrowserShowServerMessage->append(message);
}

