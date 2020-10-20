#pragma once

#include "ICommand.h"
#include <QRunnable>

namespace commands {

    class CommandAdapter : public QRunnable
    {
    public:
        CommandAdapter(ICommand& cmd);
        void run() override;
    private:
        ICommand& m_cmd;
    };

}
