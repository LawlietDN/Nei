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

        std::vector<std::string> parseArguments(int argc, char* argv[]);
        void displayUsage(std::ostream& os) const;

        bool isCommandExists(const std::vector<std::string>& args, const std::vector<std::pair<std::string, std::string>>& commands) const;
        std::vector<std::string> argumentValidator(char* argv[]);
        void InsufficientArgsMessage(std::ostream& os) const;
        void invalidCommandMessage(std::ostream& os, std::string const& command) const;
        std::vector<std::string> passArgument(int argc, char* argv[]);
        std::vector<std::string> convertArgvType(char** argv) const;
        std::vector<std::string> validateAddCommand(std::vector<std::string> const& args);
        
    };
}


