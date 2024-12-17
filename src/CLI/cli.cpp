//CHANGE CLASS NAME TO A MORE SUITABLE ONE. COMMANDHANDLER OR CLIMANAGER

#include "cli.h"
namespace cli
{
   
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
    std::vector<std::pair<std::string, std::string>> ArgumentParse::getCommands()  { return cli::ArgumentParse::commands;}
    std::vector<std::string> cli::ArgumentParse::getArguments()  { return cli::ArgumentParse::arguments;}
    std::string cli::ArgumentParse::getExtraInfo()  { return cli::ArgumentParse::extraInfo;}


    void cli::ArgumentParse::displayUsage(std::ostream& os)
    {
        auto cmdList = cli::ArgumentParse::getCommands();
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
        std::vector<std::pair<std::string, std::string>> cmd = cli::ArgumentParse::getCommands();
        std::vector<std::string> args = cli::ArgumentParse::convertArgvType(argv);
        if(argv[1] != nullptr && std::string(argv[1]) == "--help") { Utility::Helper::displayHelpCommand(); return {};}
        if(!cli::ArgumentParse::isCommandExists(args, commands)) { return{};}

        if(cli::ArgumentParse::arguments.size() < 2)
        {
            
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return{};
        
    }

    // if (args[0] == "add") { return cmdHandle::CommandHandler::validateAddCommand(args);}

    return  args;
}

    bool cli::ArgumentParse::isCommandExists(const std::vector<std::string>& args, const std::vector<std::pair<std::string, std::string>>& cmd)
{
    if (args.empty())
    {
        cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
        return false;
    }

    std::string userCommand = args[0] + ": ";
    for (const auto& command : cmd)
    {
        if (command.first == userCommand) {return true;}
    }

    cli::ArgumentParse::invalidCommandMessage(std::cerr, userCommand);
    return false;
    }


    
    void cli::ArgumentParse::InsufficientArgsMessage(std::ostream& os)
    {
        
        os <<  "Error: Insufficient arguments.\n";
        cli::ArgumentParse::displayUsage(std::cerr);
        std::exit(1); //Have to use this because I missed a fatal problem that results in a segmentation error very very early in my code. Matter of fact, I don't even know where it originates from, It was blended with the error displaying functions I made.
    }

    void cli::ArgumentParse::invalidCommandMessage(std::ostream& os, std::string const& command)
    {
        std::string sanitizedCommand;
        for (char c : command)
        {
            if (c != ':')
            {
                sanitizedCommand += c;
        }
    }
        os << "Error: Command '" << sanitizedCommand << "' is not recognized.\n";
        cli::ArgumentParse::displayUsage(std::cerr);
        std::exit(1);
    }

         std::vector<std::string> cli::ArgumentParse::passArgument(int argc, char* argv[]) 
        {

            return cli::ArgumentParse::parseArguments(argc, argv);
            
        }

        std::vector<std::string> cli::ArgumentParse::convertArgvType(char** argv) const
          {
            std::vector<std::string> processedArguments;
            for (int i = 1; argv[i] != nullptr; i++)
            {
                processedArguments.emplace_back(argv[i]); 
            }
            return processedArguments;
          }
}
