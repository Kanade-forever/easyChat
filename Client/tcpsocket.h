#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>

class tcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit tcpSocket(QObject *parent = nullptr);
    void runTcpSocket();
    void messageSend(QString message);
signals:
    void clientReceiveMessageShow(QString message);

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
