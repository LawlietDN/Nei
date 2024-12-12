//CHANGE CLASS NAME TO A MORE SUITABLE ONE. COMMANDHANDLER

#include "cli.h"
namespace cli
{
      cli::ArgumentParse::ArgumentParse() = default;
   
    void cli::ArgumentParse::parseArguments(int argc, char* argv[])
    {
        for(int i = 1; i < argc; i++)
        {
            cli::ArgumentParse::arguments.emplace_back(argv[i]);
        }
        // After validation, send argv to the task handlers
        cli::ArgumentParse::argumentValidator(argv);
    }

                                                                //Getter fucntions
    std::vector<std::pair<std::string, std::string>> ArgumentParse::getCommands() const { return cli::ArgumentParse::commands;}
    std::vector<std::string> cli::ArgumentParse::getArguments() const { return cli::ArgumentParse::arguments;}
    std::string cli::ArgumentParse::getExtraInfo() const { return cli::ArgumentParse::extraInfo;}


    void cli::ArgumentParse::displayUsage(std::ostream& os) const
    {
        auto commands = cli::ArgumentParse::getCommands();
        auto additionalInformation = cli::ArgumentParse::getExtraInfo();
        
        os << "Usage:\n";
        for(auto const& command: commands)
        {
            os << command.first << command.second;
        }
        os << '\n' << additionalInformation << '\n';
    }

    
    int cli::ArgumentParse::argumentValidator(char* argv[]) 
    {
        std::vector<std::pair<std::string, std::string>> commands = cli::ArgumentParse::getCommands();
        
        if(cli::ArgumentParse::arguments.size() < 2)
        {
            if(argv[1] != nullptr && std::string(argv[1]) == "--help") { Utility::Helper::displayHelpCommand(); return 1;}

            cli::ArgumentParse::InsufficientArgsMessage(std::cerr); return 1;
            }
        
              if(!cli::ArgumentParse::isCommandExists(argv,commands)){return 1;}
              
       
    }

    bool cli::ArgumentParse::isCommandExists(char* argv[], std::vector<std::pair<std::string, std::string>> const& commands) const
    {
        std::string userCommand = argv[1] + std::string(": ");
        for(auto const& command: commands)
        {
            if(command.first == userCommand) {return true;}

        }

        cli::ArgumentParse::invalidCommandMessage(std::cerr, userCommand);
        return false;
    }

    
    void cli::ArgumentParse::InsufficientArgsMessage(std::ostream& os) const
    {
        
        os <<  "Error: Insufficient arguments.\n";
        cli::ArgumentParse::displayUsage(std::cerr);
    }

    void cli::ArgumentParse::invalidCommandMessage(std::ostream& os, std::string const& command) const
    {
        std::string sanitizedCommand;
        for (char c : command) {
            if (c != ':') {
                sanitizedCommand += c;
        }
    }
        os << "Error: Command '" << sanitizedCommand << "' is not recognized.\n";
        cli::ArgumentParse::displayUsage(std::cerr);
    }

        char** cli::ArgumentParse::passArgument(char** argv = nullptr) const
        {
            if(argv == nullptr) { return argv;}
        }

}
