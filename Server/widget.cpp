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
    message = QDateTime::currentDateTime().toString().toUtf8() + "\n[Client]\n" + message;
    this->ui->textBrowserMessageShow->append(message);
}

void Widget::on_btnMessageSend_clicked()
{
    //输入框为空，弹出信息，防止发送
    if(this->ui->textEditMessageInput->toPlainText().isEmpty()){
        QMessageBox::information(this,"Empty!","没有输入!");
        return;
    }
    tcpserver.messageSend(this->ui->textEditMessageInput->toPlainText());//发送输入框中的信息
    this->ui->textBrowserMessageShow->append(QDateTime::currentDateTime().toString() + "\n[Server]\n" + this->ui->textEditMessageInput->toPlainText());//聊天框中添加Server发送的信息
    this->ui->textEditMessageInput->clear();//发送信息之后清除发送的信息
}


void Widget::on_btnImagSelect_clicked()
{

}

