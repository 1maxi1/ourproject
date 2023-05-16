#include "tcpserver.h"
#include "singleton.h"

tcpServer::tcpServer()
{
    m_pServer = new QTcpServer(this);

    connect(m_pServer, &QTcpServer::newConnection, this, &tcpServer::slotNewConnection);

    if(!m_pServer->listen(QHostAddress::Any, 3333))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

tcpServer::~tcpServer()
{
}


void tcpServer::slotNewConnection()     // пришел коннект от клиента
{
    QTcpSocket *pSocket = m_pServer->nextPendingConnection();
    if(!pSocket) return;

    connect(pSocket, &QTcpSocket::readyRead, this, &tcpServer::slotServerRead);
    connect(pSocket, &QTcpSocket::disconnected, this, &tcpServer::slotClientDisconnected);

    m_clients[pSocket] = QByteArray();
}

void tcpServer::slotServerRead()
{
    // срабатывает слот по сигналу от сервера readyRead
    // QObject::sender() отдает указатель на объект, который послал сигнал, у него базовый тип QObject
    QObject *object = QObject::sender();
    if (!object) return;


    // преобразовываем его в тип QTcpSocket, потому что мы знаем, что именно только сокет мог послать сигнал (мы в контрукторе вызвали connect)
    QTcpSocket *pSocket = static_cast<QTcpSocket *>(object);

    if(m_clients.contains(pSocket))
    {
        // читаем все доступные данные и пишем их в QByteArray, оссоциированный с этим сокетом
        m_clients[pSocket].append(pSocket->readAll());

        // парсим данные
        parse(pSocket);
    }
}

void tcpServer::slotClientDisconnected()
{
    // срабатывает слот по сигналу от сервера disconnected
    // QObject::sender() отдает указатель на объект, который послал сигнал, у него базовый тип QObject
    QObject *object = QObject::sender();
    if (!object) return;

    // преобразовываем его в тип QTcpSocket, потому что мы знаем, что именно только сокет мог послать сигнал (мы в контрукторе вызвали connect)
    QTcpSocket *pSocket = static_cast<QTcpSocket *>(object);

    // удаляем сокет из хэша и из памяти
    m_clients.remove(pSocket);
    m_clientsAuthorized.remove(pSocket);
    pSocket->deleteLater();
}

void tcpServer::parse(QTcpSocket *pSocket)
{
    qDebug() << "PARSE" << m_clients[pSocket];

    QByteArray data =  m_clients[pSocket];

    int indexEndOfPacket = data.indexOf("<$$END_TAG$$>");

    if(indexEndOfPacket >= 0)
    {
        qDebug() << "LEFT" << data.left(indexEndOfPacket);
        qDebug() << "mid" << data.mid(indexEndOfPacket);
    }

    m_clients[pSocket] = data.mid(indexEndOfPacket + QString("<$$END_TAG$$>").length());

    QByteArray packet = data.left(indexEndOfPacket);
    QStringList list = QString(packet).split("<$$START_BODY$$>");

    if(list.length() != 2) return;

    QString cmd = list.at(0);
    QString body = list.at(1);

    qDebug() << "Command:" << cmd;
    qDebug() << "Body:" << body;

    if(cmd == "login")
    {
        QStringList listLogPas = body.split(";");
        qDebug() << "LOGIN COMMAND" << listLogPas;

        if(listLogPas.length() != 2) return;

        QString login = QString(QByteArray::fromBase64(listLogPas.at(0).toUtf8()));
        QString password = QString(QByteArray::fromBase64(listLogPas.at(1).toUtf8()));

        qDebug() << "LOGIN PASSWORD" << login << password;

        QSqlQuery query(singleton::getInstance()->database());
        query.prepare("SELECT * FROM users WHERE login = :login;");
        query.bindValue(":login", login);

        bool isLogined = false;

        query.exec();
        while (query.next())
        {
            qDebug() << "USER:" << query.value(0).toString() << query.value(1).toString() << query.value(2).toString();
            if(query.value(2).toString() == password)
            {
                isLogined = true;
                m_clientsAuthorized[pSocket] = query.value(0).toInt();
            }
        }

        qDebug() << "LOGIN RESULT:" << isLogined;
        sendMessage(pSocket, "auth", isLogined ? "ok" : "err");
    }
    else if(cmd == "register")
    {
        QStringList listLogPasEmail = body.split(";");
        qDebug() << "REGISTER COMMAND" << listLogPasEmail;

        if(listLogPasEmail.length() != 3) return;

        QString login = QString(QByteArray::fromBase64(listLogPasEmail.at(0).toUtf8()));
        QString password = QString(QByteArray::fromBase64(listLogPasEmail.at(1).toUtf8()));
        QString email = QString(QByteArray::fromBase64(listLogPasEmail.at(2).toUtf8()));

        qDebug() << "LOGIN PASSWORD EMAIL" << login << password << email;

        QSqlQuery query(singleton::getInstance()->database());

        query.clear();
        query.prepare("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        query.bindValue(":email", email);
        query.exec();

        qDebug() << "query.lastError() " <<  query.lastError() << query.lastError().nativeErrorCode();

        if(query.lastError().nativeErrorCode() == "19")
        {
            sendMessage(pSocket, "err", "Такой логин уже существует");
        }

        if(query.lastError().nativeErrorCode().isEmpty())
        {
            m_clientsAuthorized[pSocket] = query.lastInsertId().toUInt();
            sendMessage(pSocket, "register", "ok");
            qDebug() << "query.lastInsertId()" << query.lastInsertId();
        }
    }
    else if(cmd == "get_tasks")
    {
        if(m_clientsAuthorized.contains(pSocket) && m_clientsAuthorized[pSocket] > 0)
        {
            QSqlQuery query(singleton::getInstance()->database());
            query.prepare("SELECT id, name, body FROM tasks;");
            query.exec();
            while (query.next())
            {
                qDebug() << "TASK:" << query.value(0).toString() << query.value(1).toString() << query.value(2).toString();

                QString taskName = QString(query.value(1).toString().toUtf8().toBase64());
                QString taskBody = QString(query.value(2).toString().toUtf8().toBase64());

                sendMessage(pSocket, "task", taskName + ";" + taskBody);
            }

        }
        else
        {
            sendMessage(pSocket, "err", "Ошибка авторизации");
        }

    }
}

void tcpServer::sendMessage(QTcpSocket *pSocket, QString cmd, QString body)
{
    pSocket->write((cmd + "<$$START_BODY$$>" + body + "<$$END_TAG$$>").toUtf8());
}






