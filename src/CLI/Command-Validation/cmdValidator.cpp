#include "cmdValidator.h"
namespace cmdHandle
{
    cmdHandle::CommandHandler::CommandHandler() = default;

    void cmdHandle::CommandHandler::InvalidIDmessage(std::ostream& os)
    {
        os << "Error: Invalid Task ID\n";
        cli::ArgumentParse::displayUsage(std::cerr);
    }

    std::vector<std::string> cmdHandle::CommandHandler::validateAddCommand(std::vector<std::string> const& args)
    {
        std::vector<std::string> processedArguments;

        if (args.size() < 2) {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return {};
        }

        processedArguments.push_back(args[0]); 
        processedArguments.push_back(args[1]); 

        for (size_t i = 2; i < args.size(); ++i)
        {
            if (args[i] == "-desc")
            {
                if (i + 1 < args.size())
                {
                    processedArguments.push_back(args[i]);     
                    processedArguments.push_back(args[i + 1]); 
                } 
                else
                {
                cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
                return {};
                }
            }
        }

        return processedArguments;
    }




    std::vector<std::string> cmdHandle::CommandHandler::validateDeleteCommand(std::vector<std::string> const& args)
    {
        std::vector<std::string> processedArguments;

        processedArguments.push_back(args[0]); 
    
        if (args.size() > 1)
        {
            try
            {
                int taskID = std::stoi(args[1]);
            }
            catch(std::invalid_argument const& e)
            {
                cmdHandle::CommandHandler::InvalidIDmessage(std::cerr);
                return {};
            }
            catch(std::out_of_range const& e)
            {
                cmdHandle::CommandHandler::InvalidIDmessage(std::cerr);

                return {};
            }
            processedArguments.push_back(args[1]); 
        }

        else
        {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return {};
        }
            return processedArguments;

    }


    
}