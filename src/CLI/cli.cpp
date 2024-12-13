//CHANGE CLASS NAME TO A MORE SUITABLE ONE. COMMANDHANDLER OR CLIMANAGER

#include "cli.h"
namespace cli
{
      cli::ArgumentParse::ArgumentParse() = default;
   
     std::vector<std::string> cli::ArgumentParse::parseArguments(int argc, char* argv[])
    {
        for(int i = 1; i < argc; i++)
        {
            cli::ArgumentParse::arguments.emplace_back(argv[i]);
        }
        // After validation, send argv to the task handlers
        return cli::ArgumentParse::argumentValidator(argv);
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

    
    std::vector<std::string> cli::ArgumentParse::argumentValidator(char* argv[]) 
    {
        std::vector<std::pair<std::string, std::string>> commands = cli::ArgumentParse::getCommands();
        if(!cli::ArgumentParse::isCommandExists(argv, commands)) { return{};}

        if(cli::ArgumentParse::arguments.size() < 2)
        {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return{};
        
    }
    return  cli::ArgumentParse::convertArgvType(argv);
}

    bool cli::ArgumentParse::isCommandExists(char* argv[], std::vector<std::pair<std::string, std::string>> const& commands) const
    {
        if(cli::ArgumentParse::arguments.size() < 1)
        {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return false;
        }
        if(argv[1] != nullptr && std::string(argv[1]) == "--help")
            {
                Utility::Helper::displayHelpCommand();
                return {};
            }
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

         std::vector<std::string> cli::ArgumentParse::passArgument(int argc, char* argv[]) 
        {
            return cli::ArgumentParse::parseArguments(argc, argv);
            
        }


          std::vector<std::string> cli::ArgumentParse::convertArgvType(char** argv) const
          {
            std::vector<std::string> processedArguments;
            for (int i = 1; argv[i] != nullptr; ++i)
            {
                processedArguments.emplace_back(argv[i]); 
            }
            return processedArguments;
          }

}
