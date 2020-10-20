#include "CommandAdapter.h"

namespace commands {

CommandAdapter::CommandAdapter(ICommand &cmd) : m_cmd(cmd)
{

}

void CommandAdapter::run()
{
    m_cmd.execute();
}

}
