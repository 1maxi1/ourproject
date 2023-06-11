#include <QDebug>
#include <QCoreApplication>
#include <QObject>
#include <QHostAddress>
#include <QIODevice>
#include <QMessageBox>

#include "singleton.h"

singleton::singleton()
{
    qDebug() << "Конструктор синглтона";

    m_currentRole = 0;

    m_pSock = new QTcpSocket(this);
    connect(m_pSock, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(m_pSock, SIGNAL(connected()), this, SLOT(onClientConnected()));
    connect(m_pSock, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
    connect(m_pSock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));

    connectToServer();
}

singleton::~singleton()
{
}

void singleton::onTimerReconnect()
{
    qDebug() << "TIMER";
}

void singleton::sendMessage(QString cmd, QString body)
{
    qDebug() << "SEND MESSAGE" << cmd << body << "connected:" << (m_pSock->state() == QAbstractSocket::ConnectedState)  ;

    if(m_pSock->state() == QAbstractSocket::ConnectedState)
    {
        m_pSock->write((QString(QString(m_currentLogin + ":" + m_currentPassword).toUtf8().toBase64())
        + "#" + cmd + "<$$START_BODY$$>" + body + "<$$END_TAG$$>").toUtf8());
    }
    else
    {
        m_delayedCmd = cmd;
        m_delayedBody = body;
        connectToServer();
    }

}

void singleton::connectToServer()
{
    if(m_pSock->state() != QAbstractSocket::ConnectedState && m_pSock->state() != QAbstractSocket::ConnectingState)
    {
        m_pSock->connectToHost(QHostAddress("127.0.0.1"), 3333);
    }

    if(m_pSock->state() == QAbstractSocket::ConnectedState)
    {
    }

}

void singleton::onClientConnected()
{
    qDebug() << "connected";

    if(!m_delayedCmd.isEmpty() && !m_delayedBody.isEmpty())
    {
        m_pSock->write((m_delayedCmd + "<$$START_BODY$$>" + m_delayedBody + "<$$END_TAG$$>").toUtf8());
        m_delayedCmd.clear();
        m_delayedBody.clear();
    }
}

void singleton::onClientDisconnected()
{
    qDebug() << "disconnected";
}

void singleton::onReadyRead()
{
    qDebug() << "onReadyRead";

    // срабатывает слот по сигналу от сервера readyRead
    // QObject::sender() отдает указатель на объект, который послал сигнал, у него базовый тип QObject
    QObject *object = QObject::sender();
    if (!object) return;


    // преобразовываем его в тип QTcpSocket, потому что мы знаем, что именно только сокет мог послать сигнал (мы в контрукторе вызвали connect)
    QTcpSocket *pSocket = static_cast<QTcpSocket *>(object);
    if(!pSocket) return;

    QByteArray data = pSocket->readAll();
    qDebug() << "INCOMING DATA FROM SERVER" << QString(data);

    //m_data.append(data);
    m_data += data;

    while(parse());
}

void singleton::onSokDisplayError(QAbstractSocket::SocketError err)
{
    qDebug() << "socket errot" << err;
}

bool singleton::parse()
{
    int indexEndOfPacket = m_data.indexOf("<$$END_TAG$$>");

    if(indexEndOfPacket >= 0)
    {
        qDebug() << "LEFT" << m_data.left(indexEndOfPacket);
        qDebug() << "mid" << m_data.mid(indexEndOfPacket);
    }
    else return false;

    QByteArray packet = m_data.left(indexEndOfPacket);
    QStringList list = QString(packet).split("<$$START_BODY$$>");

    m_data = m_data.mid(indexEndOfPacket + QString("<$$END_TAG$$>").length());

    if(list.length() != 2) return false;

    QString cmd = list.at(0);
    QString body = list.at(1);

    qDebug() << "Command:" << cmd;
    qDebug() << "Body:" << body;

    if(cmd == "auth")
    {
        QStringList list = body.split(":");

        if(list.length() == 2 && list[0] == "ok")
        {
            m_currentRole = list[1].toInt();
            emit authOk();
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Ошибка авторизации");
            msgBox.exec();
        }
    }
    else if(cmd == "err")
    {
        QMessageBox msgBox;
        msgBox.setText(body);
        msgBox.exec();
    }
    else if(cmd == "register")
    {
        if(body == "ok") emit registerOk();
    }
    else if(cmd == "task")
    {
        QStringList list = body.split(";");
        if(list.length() == 2) emit incomingTask(list.at(0), list.at(1));
    }
    else if(cmd == "ansReply")
    {
        emit ansReply(body);

        QMessageBox msgBox;
        msgBox.setText(body);
        msgBox.exec();

        sendMessage("get_balls", "");
    }
    else if(cmd == "tasks_balls")
    {
        emit tasksBalls(body);
    }
    else if(cmd == "stat")
    {
        emit statIncoming(body);
    }



    return true;
}

void singleton::setCurrentLogin(QString login, QString password)
{
    m_currentLogin = login;
    m_currentPassword = password;
}

QString singleton::getCurrentLogin()
{
    return m_currentLogin;
}

int singleton::getCurrentRole()
{
    return m_currentRole;
}



