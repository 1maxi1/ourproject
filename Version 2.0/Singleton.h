#ifndef SINGLETON_H
#define SINGLETON_H

#include <QSqlDatabase>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    bool connectDB();
    void disconnectDB();
    QSqlDatabase getDB() const { return db; }

private:
    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    QSqlDatabase db;
};

#endif // SINGLETON_H
