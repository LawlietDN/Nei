#include "json.h"
#include <iostream>


namespace json
{
    json::parse::parse() = default;


    void json::parse::parseToJSON(TaskData& TaskData)
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
        if(std::filesystem::exists(json::parse::fileName)) {return 1;}

        std::ofstream newFile(json::parse::fileName);
        if(!newFile) {}
        newFile << "[]";
        newFile.close();
        return 0;
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


    void json::parse::updateJSON(std::string const& argument, int ID)
    {
        if(argument == "delete")
        {
            std::cout << "Deleting Task with ID: " << ID;
        }
    }


    int json::parse::getIncrementedLastID()
    {
        std::fstream file(json::parse::fileName);
        std::string line;
        int lastID = -1;

        while(std::getline(file, line))
        {
            auto IDPostion = line.find("\"ID\":");
            if(IDPostion != std::string::npos)
            {
                int currentID = 0;
                std::stringstream ID(line.substr(IDPostion + 5));
                ID >> currentID;

                if(currentID > lastID){ lastID = currentID;}
            }
        }
        file.close();
        return lastID + 1;
    }



    bool json::parse::isTaskExist(std::string const& taskName)
    {
        std::fstream file(json::parse::fileName);
        std::string line;

        while(std::getline(file, line))
        {
            auto taskPostion = line.find("\"Task Name\":");

            if(taskPostion != std::string::npos)
            {

            size_t startPostion = line.find(":") + 2;
            size_t endPostion = line.rfind('"');
            std::string currentTaskName = line.substr(startPostion + 1, endPostion - startPostion - 1);

            if(currentTaskName == taskName)
            {
                return true;
            }
            }
        }
        return false;
    }
}