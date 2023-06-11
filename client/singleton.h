#ifndef SINGLETON_H
#define SINGLETON_H

#include <QTcpSocket>
#include <QTimer>

/*!
\brief Класс синглтон

Его объект всегда находится в единственном числе и доступен глобально во всей программе
*/

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
    int m_currentRole;

    void connectToServer();
    bool parse();

public:
    static singleton * getInstance() {
        static singleton instance;
        return &instance;
    }

    /*!
    Отправка сообщения на сервер
    \param[cmd] название команды
    \param[body] тело команды
    */
    void sendMessage(QString cmd, QString body);

    /*!
    Установка текущего логина и пароля, чтобы в любой части программы был доступ
    */
    void setCurrentLogin(QString, QString p = "");

    /*!
    Отдает текущую роль пользователя
    */
    int getCurrentRole();

    /*!
    Отдает текущий логин пользователя
    */
    QString getCurrentLogin();

public slots:
    void onTimerReconnect();

public slots:
    /// Данные пришли с сервера, можно читать
    void onReadyRead();

    /// Соединение установлено
    void onClientConnected();

    /// Соединение разорвано
    void onClientDisconnected();

    /// Ошибка сокета
    void onSokDisplayError(QAbstractSocket::SocketError);

signals:
    /// Сигнал, авторизация успешна
    void authOk();

    /// Сигнал, регистрация успешна
    void registerOk();

    /// Сигнал, пришла задача с сервера
    void incomingTask(QString name, QString body);

    /// Сигнал, ответ сервера на ответ на задачу
    void ansReply(QString body);

    /// Сигнал, пришли баллы по задаче
    void tasksBalls(QString body);

    /// Сигнал, пришла статистика
    void statIncoming(QString body);

};

#endif // SINGLETON_H
