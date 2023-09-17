#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <QTextBrowser>
#include <QList>

class tcpServer:public QObject
{
    Q_OBJECT
public:
    tcpServer();
    void runTcpServer();
    void messageSend(QString message);

signals:
    void serverMessageUpdate(QString message);
    void serverReceiveMessageShow(QString message);

public slots:
    void onNewConnect();
    void onConnected();
    void onDisConnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer server;
    QString currentMessage;
    QList<QTcpSocket*> clients;
};

#endif // TCPSERVER_H
