#pragma once

namespace commands
{
    class ICommand;
    class IWorker
    {
    public:
        virtual void run(ICommand&s) = 0;
        virtual ~IWorker(){}
    };
}
