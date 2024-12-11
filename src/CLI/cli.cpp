//CHANGE CLASS NAME TO A MORE SUITABLE ONE

#include "cli.h"
std::vector<std::pair<std::string, std::string>> setCommandVariable();
std::vector<std::pair<std::string, std::string>> cli::ArgumentParse::commands;

namespace cli
{
      cli::ArgumentParse::ArgumentParse() {
        cli::ArgumentParse::commands = setCommandVariable();
        arguments.clear();
    }
    void cli::ArgumentParse::parseArguments(int argc, char* argv[])
    {
        for(int i = 1; i < argc; i++)
        {
            cli::ArgumentParse::arguments.emplace_back(argv[i]);
        }
        cli::ArgumentParse::argumentValidator(argv);
    }
    std::vector<std::string> cli::ArgumentParse::getArguments() const {return cli::ArgumentParse::arguments;}

     void cli::ArgumentParse::displayUsage(std::ostream& os, std::vector<std::pair<std::string, std::string>>
const& commands, std::string const& additionalInformation) const
    {
        os << "Usage:\n";
        for(auto const& command: commands)
        {
            os << command.first << command.second;
        }
    }

    std::vector<std::pair<std::string, std::string>> ArgumentParse::getCommands() { return cli::ArgumentParse::commands;}
    
    int cli::ArgumentParse::argumentValidator(char* argv[])
    {
        std::vector<std::pair<std::string, std::string>> commands = cli::ArgumentParse::getCommands();
        
        if(cli::ArgumentParse::arguments.size() < 2)
        {
            std::cerr << "Error: Insufficient arguments.\n";
        displayUsage(std::cerr, cli::ArgumentParse::commands, cli::ArgumentParse::extraInfo);
        return 1;
        }

        std::string secondCommandArgument = argv[1];
        for(auto const& command: commands)
        {
            if(command.first == secondCommandArgument)
            return 0;
        }
       
    }
}

std::vector<std::pair<std::string, std::string>> setCommandVariable()
 {

    std::vector<std::pair<std::string, std::string>> commands = {
        {"add", "add [task] {description}"},
        {"delete", "delete {taskid}"},
        {"list", "list, listd, listnd, listp"},
        {"mark", "markp, markd"},
    };
    return commands;
 }