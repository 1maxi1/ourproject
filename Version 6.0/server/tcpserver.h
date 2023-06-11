#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QMap>
#include <QByteArray>

/*!
\brief Класс TCP сервер

Принимает запросы от клиентов, обрабатывает их и отвечает
*/

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

    /// слот: новое соединение
    void slotNewConnection();

    /// слот: данные готовы к чтению
    void slotServerRead();

    /// слот: соединение с клиентом разорвано
    void slotClientDisconnected();

public:

    // отправить сообщение пользователю
    void sendMessage(QTcpSocket *pSock, QString cmd, QString body);
};

#endif // TCPSERVER_H
