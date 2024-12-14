#include "taskManager.h"


namespace util
{
    util::TaskManager::TaskManager() = default;
    void util::TaskManager::manageTaskArguments(int argc, char* argv[])
    {
        cli::ArgumentParse parser;
        std::vector<std::string> arguments = parser.passArgument(argc, argv);

        if (arguments[0] == "add")
        {
            arguments = cmdHandle::CommandHandler::validateAddCommand(arguments);
            }
            else if(arguments[0] == "delete")
            {
                arguments = cmdHandle::CommandHandler::validateDeleteCommand(arguments);
            }
           
        
        

         for(auto argument: arguments)
         {
            std::cout << argument << '\n';
         }
    }
}
