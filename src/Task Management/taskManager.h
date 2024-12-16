#pragma once
#include "CLI/cli.h"
#include "Task/taskData.h"
#include "JSON/json.h"
namespace util
{
    class TaskManager
    {
public:
    TaskManager();

     void manageTaskArguments(int argc, char* argv[]);
     void manageCommands(std::vector<std::string>& arguments, TaskData& TaskData);
     int addCommand(std::vector<std::string>& arguments, TaskData& TaskData);
     void deleteCommand(std::vector<std::string>& arguments, TaskData& TaskData);
     void updateCommand(std::vector<std::string>& arguments, TaskData& TaskData);
     void markpCommand(std::vector<std::string>& arguments, TaskData& TaskData);
    };
}

