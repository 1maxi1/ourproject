#ifndef SINGLETON_H
#define SINGLETON_H

#include <QTcpSocket>
#include <QTimer>

class singleton : public QObject
{
    Q_OBJECT
private:
    // Конструкторы и оператор присваивания недоступны клиентам
    singleton();
    ~singleton();
    singleton( const singleton& );
    singleton& operator=( singleton& );

    QTcpSocket *m_pSock;
    QTimer *m_pTimer;
    QString m_delayedCmd;
    QString m_delayedBody;
    QByteArray m_data;
    QString m_currentLogin;
    QString m_currentPassword;

    void connectToServer();
    bool parse();

public:
    static singleton * getInstance() {
        static singleton instance;
        return &instance;
    }

    void sendMessage(QString cmd, QString body);
    void setCurrentLogin(QString, QString p = "");
    QString getCurrentLogin();

public slots:
    void onTimerReconnect();

public slots:
    void onReadyRead();
    void onClientConnected();
    void onClientDisconnected();
    void onSokDisplayError(QAbstractSocket::SocketError);

signals:
    void authOk();
    void registerOk();
    void incomingTask(QString name, QString body);
    void ansReply(QString body);
    void tasksBalls(QString body);
};

#endif // SINGLETON_H
