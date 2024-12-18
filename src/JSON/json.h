#pragma once
#include "Task/taskData.h"
#include "Utility/utility.h"
#include <filesystem>
#include <fstream>





namespace json
{
    class parse
    {
    private:
        inline static const std::string fileName = "TaskList.json";

    public:

        static int initializeJSONfile();
        static void parseToJSON(TaskData& TaskData);
        static std::string trimJSON(std::string const& existingContent);
        static void updateJSON(std::vector<std::string> const& argument, int ID, TaskData& TaskData);
        static int getIncrementedLastID();
        static bool isTaskExist(std::string const& taskName);
        static bool isIDExist(int taskID);
        static void deleteTask(int taskID);
        static std::vector<std::string> loadFileToVector();
        static void displayTaskList();
        static void updateTask(std::string const& argument, int taskID,  TaskData& TaskData);

    };
}