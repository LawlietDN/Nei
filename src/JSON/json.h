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
        static void parseToJson(TaskData& TaskData);
        static std::string trimJSON(std::string const& existingContent);
    };
}