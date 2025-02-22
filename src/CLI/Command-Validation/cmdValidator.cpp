#include "cmdValidator.h"
namespace cmdHandle
{

    std::vector<std::string> cmdHandle::CommandHandler::validateAddCommand(std::vector<std::string> const& args)
    {
        std::vector<std::string> processedArguments;

        if (args.size() < 2) {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return {};
        }

        processedArguments.push_back(args[0]); 
        processedArguments.push_back(args[1]); 

        for (size_t i = 2; i < args.size(); i++)
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




    std::vector<std::string> cmdHandle::CommandHandler::validateMarkpAndDeleteAndMarkdAndUpdateCommand(std::vector<std::string> const& args)
    {
        std::vector<std::string> processedArguments;

        processedArguments.push_back(args[0]); 
        if (args.size() < 2)
        {
            cli::ArgumentParse::InsufficientArgsMessage(std::cerr);
            return {};
        }
        int taskID = 0;
        
            try
            {
                 taskID = std::stoi(args[1]);
            }
            catch(std::exception const& e)
            {
                Utility::Helper::InvalidIDmessage(std::cerr);
                return {}; 
            }
            processedArguments.push_back(args[1]);
            
             if (args[0] == "update")
             {
                if (args.size() > 2)
                {
            processedArguments.push_back(args[2]); 
                }
                else
                {
                    Utility::Helper::InvalidIDmessage(std::cerr);
                }
        }

        
            return processedArguments;

    }
}