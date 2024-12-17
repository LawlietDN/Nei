#include "taskManager.h"

namespace util
{
    void util::TaskManager::manageTaskArguments(int argc, char* argv[])
    {
        TaskData TaskData;
        cli::ArgumentParse parser;
        std::vector<std::string> arguments = parser.passArgument(argc, argv);
        util::TaskManager::manageCommands(arguments, TaskData);
    }

    void util::TaskManager::manageCommands(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        util::TaskManager::addCommand(arguments, TaskData);
        util::TaskManager::deleteCommand(arguments, TaskData);
        util::TaskManager::markpCommand(arguments, TaskData);
        util::TaskManager::updateCommand(arguments, TaskData);
    }





    int util::TaskManager::addCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if (arguments[0] == "add")
        {
            arguments = cmdHandle::CommandHandler::validateAddCommand(arguments);
            if(json::parse::isTaskExist(arguments[1])) { Utility::Helper::displayTaskExistsMessage(std::cerr); return 1;}
            TaskData.task = arguments[1];

            TaskData.description = "None";
            TaskData.status = "In-Progress";

            if(arguments.size() > 2) { TaskData.description = arguments[3];}
            TaskData.createdAt = Utility::Helper::getCurrentTime();
            TaskData.updatedAt = Utility::Helper::getCurrentTime();
            TaskData.taskID = json::parse::getIncrementedLastID();
            json::parse::parseToJSON(TaskData);

            }
    }

    
    void util::TaskManager::deleteCommand(std::vector<std::string>& arguments, TaskData& TaskData)
    {
        if(arguments[0] == "delete")
            {
                arguments = cmdHandle::CommandHandler::validateMarkpAndDeleteAndMarkdAndUpdateCommand(arguments);
                json::parse::updateJSON(arguments[0], std::stoi(arguments[1]));
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
