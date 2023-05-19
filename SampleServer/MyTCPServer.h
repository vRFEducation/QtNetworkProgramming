#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTCPServer(int port, QObject *parent = nullptr);
    bool isStarted() const;
    void sendToAll(QString message);
signals:
    void newClientConnected();
    void clientDisconnect();
    void dataReceived(QString message);

private slots:
    void on_client_connecting();

    void clientDisconnected();

    void clientDataReady();


private:
    QTcpServer *_server;
    QList<QTcpSocket *> _socketsList;
    bool _isStarted;
};

#endif // MYTCPSERVER_H
