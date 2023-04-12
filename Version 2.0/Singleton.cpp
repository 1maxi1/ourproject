#include "singleton.h"
#include <QSqlError>
#include <QDebug>

Singleton::Singleton() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");
}

bool Singleton::connectDB() {
    if (!db.open()) {
        qDebug() << "Failed to connect to database:";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "Connected to database!";
    return true;
}

void Singleton::disconnectDB() {
    db.close();
    qDebug() << "Disconnected from database!";
}
