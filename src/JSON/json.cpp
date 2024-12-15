#include "json.h"


namespace json
{
    json::parse::parse() = default;


    void json::parse::parseToJson(TaskData& TaskData)
    {
        
        std::string fileName = "TaskList.json";
        std::ofstream file(fileName);
        std::ifstream ifile(fileName);
        std::string existingContent, line;

        initializeJSONfile(fileName);
        while (std::getline(ifile, line)) {
            existingContent += line;
        }
        ifile.close();

        if (!existingContent.empty() && existingContent.back() == ']') {
            existingContent.pop_back(); 
            if (existingContent.size() > 1) {
                existingContent += ",\n"; 
            }
        } else {
            existingContent = "[\n\n";                                          //INCOMPLETE
        }
        if(file)
        {
            file << existingContent;
            file << "    {\n"
                    << "        \"ID\": " << TaskData.taskID << ",\n"
                    << "        \"Task Name\": \"" << TaskData.task << "\",\n"
                    << "        \"Description\": \"" << TaskData.description << "\",\n"
                    << "        \"Created_at\": \"" << TaskData.createdAt << "\",\n"
                    << "        \"Updated_at\": \"" << TaskData.updatedAt << "\",\n"
                    << "        \"status\": \"" << TaskData.status << "\"\n"
                    << "    }";

            file << "\n\n]";
            file.close();
        }
        

    }


    int json::parse::initializeJSONfile(std::string const& fileName)
    {
        if(std::filesystem::exists(fileName)) {return 1;}

        std::ofstream newFile(fileName);
        newFile << "[]";
        newFile.close();
    }
};