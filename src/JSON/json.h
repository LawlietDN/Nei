#include "Task/taskData.h"
#include <filesystem>
#include <fstream>





namespace json
{
    class parse
    {

    public:
        parse();

        static int initializeJSONfile(std::string const& fileName);
        static void parseToJson(TaskData& TaskData);
    };
}