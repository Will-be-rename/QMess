#include <QCoreApplication>

#include "serverrunner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerRunner srv;
    srv.StartServer();

    return a.exec();
}
