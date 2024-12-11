#pragma once
#include <vector>
#include <iostream>


namespace cli
{
    class ArgumentParse
    {
    private:
    std::vector<std::string> arguments;
    static std::vector<std::pair<std::string, std::string>> commands;

    std::string extraInfo = 
        "For more description on each command enter nei --help\n"
        "For a specific command: nei --help mark or the command you want.";

    public:
        ArgumentParse();
        void parseArguments(int argc, char* argv[]);
        std::vector<std::string> getArguments() const;
        void displayUsage(std::ostream& os, std::vector<std::pair<std::string, std::string>>
const& commands, std::string const& additionalInformation) const;

        int argumentValidator(char* argv[]);
        static std::vector<std::pair<std::string, std::string>> getCommands();

        
    };
}


