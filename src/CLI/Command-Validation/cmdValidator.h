#pragma once
#include "CLI/cli.h"
namespace cmdHandle
{
    class CommandHandler
    {
    public:
        CommandHandler();

        static std::vector<std::string> validateAddCommand(std::vector<std::string> const& args);
        static std::vector<std::string> validateDeleteCommand(std::vector<std::string> const& args);
        static void InvalidIDmessage(std::ostream& os);
        static std::vector<std::string> validateMarkPCommand(std::vector<std::string> const& args);
        static int taskIDGenerator(int lastID);
    };
}
