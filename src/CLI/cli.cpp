//CHANGE CLASS NAME TO A MORE SUITABLE ONE. COMMANDHANDLER

#include "cli.h"
namespace cli
{
      cli::ArgumentParse::ArgumentParse() {
        cli::ArgumentParse::extraInfo;
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

    std::vector<std::pair<std::string, std::string>> ArgumentParse::getCommands(){ return cli::ArgumentParse::commands;}
    std::vector<std::string> cli::ArgumentParse::getArguments(){ return cli::ArgumentParse::arguments;}
    std::string cli::ArgumentParse::getExtraInfo(){ return cli::ArgumentParse::extraInfo;}


    void cli::ArgumentParse::displayUsage(std::ostream& os, std::vector<std::pair<std::string, std::string>>
const& commands, std::string const& additionalInformation) const
    {
        
        os << "Usage:\n";
        for(auto const& command: commands)
        {
            os << command.first << command.second;
        }
    }

    
    int cli::ArgumentParse::argumentValidator(char* argv[])
    {
        std::vector<std::pair<std::string, std::string>> commands = cli::ArgumentParse::getCommands();
        
        if(cli::ArgumentParse::arguments.size() < 2) { InsufficientArgsMessage(std::cerr); return 1;}
        
        
        std::string secondCommandArgument = argv[1];
        for(auto const& command: commands)
        {
            if(command.first == secondCommandArgument)
            {

            }
            return 0;
        }
       
    }

    
    void cli::ArgumentParse::InsufficientArgsMessage(std::ostream& os)
    {
        
        os <<  "Error: Insufficient arguments.\n";
        cli::ArgumentParse::displayUsage(std::cerr, cli::ArgumentParse::getCommands(), cli::ArgumentParse::getExtraInfo());
    }
}
