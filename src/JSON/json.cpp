#include "json.h"


namespace json
{
    json::parse::parse() = default;


    void json::parse::parseToJson()
    {
        std::string fileName = "TaskList.json";
        std::ofstream file(fileName);
        initializeJSONfile(fileName);
        
    }


    int json::parse::initializeJSONfile(std::string const& fileName)
    {
        if(std::filesystem::exists(fileName)) {return 1;}

        std::ofstream newFile(fileName);
        newFile << "[]";
        newFile.close();
    }
};