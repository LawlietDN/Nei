#pragma once
#include <iostream>
#include "Utility/utility.h"


namespace cli
{
    class ArgumentParse
    {
    private:
    std::vector<std::string> arguments;
    std::vector<std::pair<std::string, std::string>> commands = Utility::Helper::setCommandsVariable();
    std::string extraInfo = Utility::Helper::setExtraInfoVariable();

    public:
        ArgumentParse();
        void parseArguments(int argc, char* argv[]);
        std::vector<std::string> getArguments();
        void displayUsage(std::ostream& os, std::vector<std::pair<std::string, std::string>>
const& commands, std::string const& additionalInformation) const;

        int argumentValidator(char* argv[]);
        std::vector<std::pair<std::string, std::string>> getCommands();
        std::string getExtraInfo(); 
        void InsufficientArgsMessage(std::ostream& os);

        
    };
}


