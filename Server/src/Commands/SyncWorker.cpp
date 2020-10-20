#include "SyncWorker.h"

#include <QDebug>

namespace commands {

    SyncWorker::SyncWorker()
    {

    }

    void SyncWorker::run(ICommand & cmd)
    {
        qDebug() << "Starting executing " << cmd.name().c_str();
        ResultType result = cmd.execute();
        qDebug() << "Result of " << cmd.name().c_str() << " : " << cmd.resultToString(result).c_str();
    }
}
