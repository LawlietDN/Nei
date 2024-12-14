
#include "utility.h"
#include <fstream>

namespace Utility
{

    std::vector<std::pair<std::string, std::string>> Utility::Helper::setCommandsVariable()
    {

        std::vector<std::pair<std::string, std::string>> commands = {
            {"add: ", "add [task] {-desc is optional, you can omit it if you want}--> -desc {description}\n"},
            {"delete: ", "delete {taskID}\n"},
            {"list: ", "list, listd, listnd, listp\n"},
            {"markd: ", "markd {taskID}\n"},
            {"markp: ", "markp {taskID}\n"},
        };
        return commands;
    }

    std::string Utility::Helper::setExtraInfoVariable()
    {
        std::string ExtraInfo =
        "For more detailed description on how to use each command enter nei --help\n"
        "For a specific command: nei --help {command}";
        return ExtraInfo;
    }

    int Utility::Helper::displayHelpCommand()
    {
        std::string fileName =  "src/CLI/Utility/helpMessage.txt";
        std::ifstream file(fileName);
        std::string line;

        if(!file) {std::cerr << "Unable to open file: " << fileName << '\n'; return 1;}

         while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        return 0;
    }
}