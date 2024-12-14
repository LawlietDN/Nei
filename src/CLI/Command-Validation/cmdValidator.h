#pragma once
#include "CLI/cli.h"
namespace cmdHandle
{
    class CommandHandler
    {
    public:
        CommandHandler();

        static std::vector<std::string> validateAddCommand(std::vector<std::string> const& args);
    };
}
