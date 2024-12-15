#include "Task/taskData.h"
#include <filesystem>
#include <fstream>




namespace json
{
    class parse
    {
        parse();

        int initializeJSONfile(std::string const& fileName);
        void parseToJson();
    };
}