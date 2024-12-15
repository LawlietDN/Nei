#include "json.h"


namespace json
{
    json::parse::parse() = default;


    void json::parse::parseToJson(TaskData& TaskData)
    {
    initializeJSONfile(json::parse::fileName);
    
    std::ifstream ifile(json::parse::fileName);
    std::string existingContent, line;
    while (std::getline(ifile, line))
    {
        existingContent += line + "\n";
    }
    ifile.close();

   
    std::string trimmedContent = json::parse::trimJSON(existingContent);
    

    trimmedContent += "    \n\t{\n"
               "        \"ID\": " + std::to_string(TaskData.taskID) + ",\n"
               "        \"Task Name\": \"" + TaskData.task + "\",\n"
               "        \"Description\": \"" + TaskData.description + "\",\n"
               "        \"Created_at\": \"" + TaskData.createdAt + "\",\n"
               "        \"Updated_at\": \"" + TaskData.updatedAt + "\",\n"
               "        \"status\": \"" + TaskData.status + "\"\n"
               "    }";

    trimmedContent += "\n]";

    std::ofstream file(json::parse::fileName);
    file << trimmedContent;
    file.close();
        

    }


    int json::parse::initializeJSONfile(std::string const& fileName)
    {
        if(std::filesystem::exists(fileName)) {return 1;}

        std::ofstream newFile(fileName);
        newFile << "[]";
        newFile.close();
    }


    std::string json::parse::trimJSON(std::string const& existingContent)
    {
        std::string trimmedContent = existingContent;
        if (!trimmedContent.empty())
    {
        while (isspace((unsigned char)trimmedContent.back()))
        {
            trimmedContent.pop_back();
        }

        if (trimmedContent.back() == ']')
        {
            trimmedContent.pop_back();

            while ((trimmedContent.back() == '\n' || trimmedContent.back() == ','))
            {
                trimmedContent.pop_back();
            }
        }
    }

    if (trimmedContent.empty() || trimmedContent == "[") {
        trimmedContent = "[";
    }

    if (trimmedContent.size() > 1) {
        trimmedContent += ",";
    }

    return trimmedContent;
    }
}