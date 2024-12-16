#include "Task/taskData.h"
#include <filesystem>
#include <fstream>





namespace json
{
    class parse
    {
    private:
        inline static const std::string fileName = "TaskList.json";

    public:
        parse();

        static int initializeJSONfile(std::string const& fileName);
        static void parseToJSON(TaskData& TaskData);
        static std::string trimJSON(std::string const& existingContent);
        static void updateJSON(std::string const& argument, int ID);
        static int getIncrementedLastID();
        static bool isTaskExist(std::string const& taskName);
    };
}