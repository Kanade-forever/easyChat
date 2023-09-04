#include "tcpsocket.h"

tcpSocket::tcpSocket(QObject *parent) : QObject(parent)
{

}

void tcpSocket::runTcpSocket()
{
    connect(&socket,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(&socket,SIGNAL(disconnected()),
            this,SLOT(onDisConnected()));
/*    connect(&socket,SIGNAL(readyRead()),
            this,SLOT(onReadyRead()));*/
    connect(&socket,&QIODevice::readyRead,
            this,&tcpSocket::onReadyRead);
    connect(&socket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(onError(QAbstractSocket::SocketError)));

    socket.connectToHost("127.0.0.1",1234);

}

void tcpSocket::onConnected()
{
    qDebug()<<"[Client]:Connected";
}

void tcpSocket::onDisConnected()
{
    qDebug()<<"[Client]:Disconnected";
}

void tcpSocket::onReadyRead()
{
    QObject *obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    QByteArray date = socket->readAll();
    qDebug()<<"[Client]:"<<date;
}

void tcpSocket::onError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"[Client]:"<<socketError;
}
