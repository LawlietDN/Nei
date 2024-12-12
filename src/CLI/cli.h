#pragma once
#include "Utility/utility.h"


namespace cli
{
    class ArgumentParse
    {
    private:
    std::vector<std::string> arguments;
    inline static const std::vector<std::pair<std::string, std::string>> commands = Utility::Helper::setCommandsVariable();
    inline static const std::string extraInfo = Utility::Helper::setExtraInfoVariable();

    public:
        ArgumentParse();                //Getter functions
        std::vector<std::pair<std::string, std::string>> getCommands() const;
        std::string getExtraInfo() const; 
        std::vector<std::string> getArguments() const;

        void parseArguments(int argc, char* argv[]);
        void displayUsage(std::ostream& os) const;

        bool isCommandExists(char* argv[], std::vector<std::pair<std::string, std::string>> const& commands) const;
        int argumentValidator(char* argv[]);
        void InsufficientArgsMessage(std::ostream& os) const;
        void invalidCommandMessage(std::ostream& os, std::string const& command) const;
        char** passArgument(char** argv = nullptr) const;

        
    };
}


