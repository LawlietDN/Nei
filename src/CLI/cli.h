#pragma once
#include "utility.h"
#include "CLI/Command-Validation/cmdValidator.h"


namespace cli
{
    class ArgumentParse
    {
    private:
    std::vector<std::string> arguments;
    inline static const std::vector<std::pair<std::string, std::string>> commands = Utility::Helper::setCommandsVariable();
    inline static const std::string extraInfo = Utility::Helper::setExtraInfoVariable();

    public:
                            //Getter functionsg
        static std::vector<std::pair<std::string, std::string>> getCommands();
        static std::string getExtraInfo();
        std::vector<std::string> getArguments();

        std::vector<std::string> parseArguments(int argc, char* argv[]);
        static void displayUsage(std::ostream& os);

        bool isCommandExists(const std::vector<std::string>& args, const std::vector<std::pair<std::string, std::string>>& cmd);
        std::vector<std::string> argumentValidator(char* argv[]);
        static void InsufficientArgsMessage(std::ostream& os);
        static void invalidCommandMessage(std::ostream& os, std::string const& command);
        std::vector<std::string> passArgument(int argc, char* argv[]);
        std::vector<std::string> convertArgvType(char** argv) const;
        
        
    };
}


