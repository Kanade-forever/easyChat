#include "tcpserver.h"

tcpServer::tcpServer()
{

}

void tcpServer::runTcpServer()
{
    connect(&server,SIGNAL(newConnection()),
            this,SLOT(onNewConnect()));

    bool listenOk = server.listen(QHostAddress::AnyIPv4,1234);//是否监听成功 anyIpv4 == 0.0.0.0 监听任意ip
    qDebug()<<"listen to AnyAddress:1234  :"<<listenOk;
    QString stringListenOk = listenOk?"true":"false";
    emit this->serverMessageUpdate("listen to AnyAddress:1234 :" + stringListenOk);
}

void tcpServer::messageSend(QString message)
{
    this->currentMessage = message;
    for(QList<QTcpSocket*>::iterator itr = clients.begin();itr != clients.end();itr++){
        QTcpSocket *client = *itr;
        client->write(message.toUtf8());
    }
}

void tcpServer::onNewConnect()
{
    //获取连接的客户端
    QTcpSocket *socket = server.nextPendingConnection();
    this->clients.append(socket);

    //在建立连接之后在进行相关连接操作
    connect(socket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),
            this,SLOT(onDisConnected()));
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(onError(QAbstractSocket::SocketError)));
}

void tcpServer::onConnected()
{
    emit this->serverMessageUpdate("[Server]:Connected");
    qDebug()<<"1";
}

void tcpServer::onDisConnected()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    this->clients.removeAll(socket);
    socket->deleteLater();

    emit this->serverMessageUpdate("[Server]:Disconnected");
    qDebug()<<"2";
}

void tcpServer::onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);//this->sender()获取该信号的发送者，返回一个obj，需要(qobject_cast<template>(obj))类型转换
    QByteArray socketDate = socket->readAll();
    emit this->serverReceiveMessageShow(socketDate);//激活serverReceiveMessageShow信号，在widget中会由on*响应，设置ui中的show

//    emit this->serverMessageUpdate( "[Server]:" + socketDate);
//    qDebug()<<"3";
//    QTcpSocket *socket = qobject_cast<QTcpSocket*>(this->sender());
}

void tcpServer::onError(QAbstractSocket::SocketError socketError)
{
    emit this->serverMessageUpdate("[Server]:" + QString::number(socketError));
    qDebug()<<"4";
}
