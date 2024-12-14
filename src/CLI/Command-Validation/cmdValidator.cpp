#include "cmdValidator.h"

namespace cmdHandle
{
    cmdHandle::CommandHandler::CommandHandler() = default;



    std::vector<std::string> cmdHandle::CommandHandler::validateAddCommand(std::vector<std::string> const& args)
    {
   
    std::vector<std::string> processedArguments;
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
            } else
            {
               std::cout << "Debug: Inside Command validation file.";
                return {};
            }
        }
    }

    return processedArguments;
    }
}