#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");
    tcpsocket.runTcpSocket();
}

Widget::~Widget()
{
    delete ui;
}

