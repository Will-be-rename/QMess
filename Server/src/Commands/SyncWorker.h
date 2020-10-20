#pragma once

#include "IWorker.h"
#include "ICommand.h"

namespace commands {

    class SyncWorker : public IWorker
    {
    public:
        SyncWorker();
        void run(ICommand&) override;
    };
}
