#include "taskManager.h"


namespace util
{
    util::TaskManager::TaskManager() = default;
    void util::TaskManager::manageTaskArguments(int argc, char* argv[])
    {
        TaskData TaskData;
        cli::ArgumentParse parser;
        std::vector<std::string> arguments = parser.passArgument(argc, argv);

        util::TaskManager::manageCommands(arguments, TaskData);
        std::cout << "Task is: " << TaskData.task << '\n';
        std::cout << "Description is: " << TaskData.description << '\n';
    }

    void util::TaskManager::manageCommands(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        util::TaskManager::addCommand(arguments, TaskData);
        util::TaskManager::deleteCommand(arguments, TaskData);
        util::TaskManager::markpCommand(arguments, TaskData);
        util::TaskManager::updateCommand(arguments, TaskData);
    }





    void util::TaskManager::addCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if (arguments[0] == "add")
        {
            arguments = cmdHandle::CommandHandler::validateAddCommand(arguments);
            TaskData.task = arguments[1];
            // int lastID = 0;//parseLastID() //Implementing this soon
            //TaskData.taskID = cmdHandle::CommandHandler::taskIDGenerator();
            TaskData.description = "None";
            TaskData.status = "In-Progress";

            if(arguments.size() > 2) { TaskData.description = arguments[3];}
            TaskData.createdAt = Utility::Helper::getCurrentTime();
            TaskData.updatedAt = Utility::Helper::getCurrentTime();
            json::parse::parseToJson(TaskData);

            }
    }

    
    void util::TaskManager::deleteCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if(arguments[0] == "delete")
            {
                arguments = cmdHandle::CommandHandler::validateMarkpAndDeleteAndMarkdAndUpdateCommand(arguments);
            
            }
    }


    void util::TaskManager::markpCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if(arguments[0] == "markp")
            {
            arguments = cmdHandle::CommandHandler::validateMarkpAndDeleteAndMarkdAndUpdateCommand(arguments);
            
        }
    }

    void util::TaskManager::updateCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if(arguments[0] == "update")
            {
                arguments = cmdHandle::CommandHandler::validateMarkpAndDeleteAndMarkdAndUpdateCommand(arguments);
                
            }
    }
}
