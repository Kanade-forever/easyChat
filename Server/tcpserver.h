#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <QTextBrowser>

class tcpServer:public QObject
{
    Q_OBJECT
public:
    tcpServer();
    void runTcpServer();

signals:
    void serverMessageUpdate(QString message);

public slots:
    void onNewConnect();
    void onConnected();
    void onDisConnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer server;
};

#endif // TCPSERVER_H
