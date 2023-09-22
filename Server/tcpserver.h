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
    void runTcpServer();//在widget中添加server的逻辑
    void messageSend(QString message);//发送信息

signals:
    void serverMessageUpdate(QString message);//server的状态更新信号
    void serverReceiveMessageShow(QString message);//server收到信息

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
