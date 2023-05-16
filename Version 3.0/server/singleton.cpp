#include "singleton.h"

singleton::singleton()
{
    qDebug() << "Конструктор синглтона";

    // БАЗА ДАННЫХ

    m_database = QSqlDatabase::addDatabase("QSQLITE");  // инициализация, выбор драйвера БД
    m_database.setDatabaseName("data.db");              // выставляем название БД

    if (!m_database.open()) {
        qDebug() << "Ошибка открытия бд:" << m_database.lastError().text();
    }

    QSqlQuery query(m_database);
    query.prepare("CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT UNIQUE, password TEXT, email TEXT);");
    query.exec();

    query.clear();
    query.prepare("CREATE TABLE IF NOT EXISTS tasks(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE, body TEXT);");
    query.exec();

    query.clear();
    query.prepare("CREATE TABLE IF NOT EXISTS solution(user_id INTEGER, task_id INTEGER, answer TEXT);");
    query.exec();


    // Настройка сети

    m_pServer = new tcpServer();

}

singleton::~singleton()
{
    qDebug() << "Деструктор синглтона";

    m_pServer->deleteLater();
}

QSqlDatabase &singleton::database()
{
    return m_database;
}

