#pragma once

#include "ICommand.h"
#include "modelsAPI.h"
#include "../DataProviders/idataprovider.h"

#include <QTcpSocket>

namespace commands
{

    class SetupUserCommand : public ICommand
    {
    public:
        SetupUserCommand(const LoginPackage& , QTcpSocket&, IDataProvider& );
        virtual std::string name() override;
        virtual std::string resultToString(ResultType) override;
        virtual ResultType execute() override;
    private:
        const LoginPackage& m_loginData;
        QTcpSocket& m_socket;
        IDataProvider& m_dataProvider;
    };
}
