#pragma once

#include "string"

namespace commands {

    enum ResultType
    {
        Ok,
        Failed
    };

    class ICommand
    {
      public:
        virtual ResultType execute() = 0;
        virtual std::string name() = 0;
        virtual std::string resultToString(ResultType) = 0;
        virtual ~ICommand(){}
    };
}
