#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class tcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit tcpSocket(QObject *parent = nullptr);
    void runTcpSocket();

public slots:
    void onConnected();
    void onDisConnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError);

signals:

private:
    QTcpSocket socket;

};

#endif // TCPSOCKET_H