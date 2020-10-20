#include <QCoreApplication>

#include "serverrunner.h"
#include "Commands/SyncWorker.h"
#include "DataProviders/mockdataprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    commands::SyncWorker worker;
    MockDataProvider dataprovider;
    ServerRunner srv(worker, dataprovider);
    srv.StartServer();

    return a.exec();
}
