#include <vector>
#include <string>
#include "utility.h"
namespace Utility
{

    std::vector<std::pair<std::string, std::string>> Utility::Helper::setCommandsVariable()
    {

        std::vector<std::pair<std::string, std::string>> commands = {
            {"add: ", "add [task] {description}\n"},
            {"delete: ", "delete {taskid}\n"},
            {"list: ", "list, listd, listnd, listp\n"},
            {"mark: ", "markp, markd\n"},
        };
        return commands;
    }

    std::string Utility::Helper::setExtraInfoVariable()
    {
        std::string ExtraInfo =
        "For more description on each command enter nei --help\n"
        "For a specific command: nei --help {command}";
        return ExtraInfo;
    }
}