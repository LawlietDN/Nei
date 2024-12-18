#pragma once
#include "CLI/cli.h"
namespace cmdHandle
{
    class CommandHandler
    {
    public:
        static std::vector<std::string> validateAddCommand(std::vector<std::string> const& args);
        static std::vector<std::string> validateMarkpAndDeleteAndMarkdAndUpdateCommand(std::vector<std::string> const& args);
    };
}
