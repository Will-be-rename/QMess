#include "SetupUserCommand.h"

#include <QDataStream>

namespace commands
{

    SetupUserCommand::SetupUserCommand(const LoginPackage& login, QTcpSocket& socket, IDataProvider& dataprovider)
        : m_loginData(login),
          m_socket(socket),
          m_dataProvider(dataprovider){}

    std::string SetupUserCommand::name()
    {
        return std::string("SetupUserCommand");
    }
    std::string SetupUserCommand::resultToString(ResultType type)
    {
        switch(type)
        {
            case ResultType::Ok:
                return "Ok";
        }
        return "Unknown";
    }

    ResultType SetupUserCommand::execute()
    {
        try
        {
            auto user = m_dataProvider.getUserData(m_loginData).value();
            QByteArray data;
            QDataStream ds(&data, QIODevice::ReadWrite);
            ds.setVersion(QDataStream::Qt_5_11);
            ds << eCurrentUserResponse <<  user;
            m_socket.write(data);
        }
        catch(...)
        {
            return ResultType::Ok;
        }
        return ResultType::Ok;
    }
}
