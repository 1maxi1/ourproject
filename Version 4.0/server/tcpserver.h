#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QMap>
#include <QByteArray>

class tcpServer : public QObject
{
    Q_OBJECT
public:
    tcpServer();
    ~tcpServer();

private:
    QTcpServer *m_pServer;        // объект сервер
    //QTcpSocket * m_pTcpSocket;
    //QList<QTcpSocket *> m_listSockets;

    // ассоциативный список сокет->массив данных
    QMap<QTcpSocket *, QByteArray> m_clients;
    QMap<QTcpSocket *, int> m_clientsAuthorized;

    bool parse(QTcpSocket *pSocket);

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

public:
    void sendMessage(QTcpSocket *pSock, QString cmd, QString body);
};

#endif // TCPSERVER_H
