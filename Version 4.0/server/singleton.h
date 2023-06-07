#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtSql>    // подключаем заголовочный файл баз данных
#include <QTcpServer>
#include <tcpserver.h>

class singleton //: public QObject
{
    //Q_OBJECT
private:
    // Конструкторы и оператор присваивания недоступны клиентам
    singleton();
    singleton( const singleton& );
    singleton& operator=( singleton& );

    QSqlDatabase m_database;    // объект доступа к БД
    tcpServer *m_pServer;       // объект сервера


public:
    ~singleton();

    static singleton * getInstance() {
        static singleton instance;
        return &instance;
    }

    QSqlDatabase &database();
};

#endif // SINGLETON_H
