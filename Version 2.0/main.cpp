#include <QCoreApplication>
#include "mytcpserver.h"
#include "Singleton.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;

    Singleton& singleton = Singleton::getInstance();

        if (!singleton.connectDB()) {
            return 1;
        }

        // Делаем что-нибудь

        singleton.disconnectDB();

    return a.exec();
}
