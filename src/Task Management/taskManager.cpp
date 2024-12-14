#include "taskManager.h"


namespace util
{
    util::TaskManager::TaskManager() = default;
    void util::TaskManager::manageTaskArguments(int argc, char* argv[])
    {
        TaskData TaskData;
        cli::ArgumentParse parser;
        std::vector<std::string> arguments = parser.passArgument(argc, argv);

        if (arguments[0] == "add")
        {
            arguments = cmdHandle::CommandHandler::validateAddCommand(arguments);
            TaskData.task = arguments[1];
            int lastID = //parseLastID() //Implementing this soon
            TaskData.taskID = cmdHandle::CommandHandler::taskIDGenerator(lastID);
            if(arguments.size() > 2)
            {
                TaskData.description = arguments[3];
            }
            }
            else if(arguments[0] == "delete")
            {
                arguments = cmdHandle::CommandHandler::validateDeleteCommand(arguments);

            }
            else if(arguments[0] == "markp")
            {
                arguments = cmdHandle::CommandHandler::validateMarkPCommand(arguments);
            }

            std::cout << "Task is: " << TaskData.task << '\n';
            std::cout << "Description is: " << TaskData.description << '\n';
         for(auto argument: arguments)
         {
            std::cout << argument << '\n';
         }
    }
}
