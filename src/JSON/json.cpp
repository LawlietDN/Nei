
#include "json.h"

    namespace json
    {


        void json::parse::parseToJSON(TaskData& TaskData)
        {
        initializeJSONfile();
        
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
                "        \"Status\": \"" + TaskData.status + "\"\n"
                "    }";

        trimmedContent += "\n]";

        std::ofstream file(json::parse::fileName);
        file << trimmedContent;
        file.close();
            

        }


        int json::parse::initializeJSONfile()
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


        void json::parse::updateJSON(std::vector<std::string> const& argument, int ID)
        {
            if(argument[0] == "delete")
            {
                if(!json::parse::isIDExist(ID)) {Utility::Helper::InvalidIDmessage(std::cerr);}
                json::parse::deleteTask(ID);
            }
            else if(argument[0] == "update")
            {
                if(!json::parse::isIDExist(ID)) {Utility::Helper::InvalidIDmessage(std::cerr);}
                json::parse::updateTask(argument[2], ID);
            }
            else if(argument[0] == "markp")
            {
                if(!json::parse::isIDExist(ID)) {Utility::Helper::InvalidIDmessage(std::cerr);}
                json::parse::markpTask(argument[2], ID);
            }
            else if(argument[0] == "markc")
            {
                if(!json::parse::isIDExist(ID)) {Utility::Helper::InvalidIDmessage(std::cerr);}
                json::parse::markdTask(argument[2], ID);
            }
        }


        int json::parse::getIncrementedLastID()
        {
            std::fstream file(json::parse::fileName);
            std::string line;
            int lastID = -1;

            while(std::getline(file, line))
            {
                size_t IDPostion = line.find("\"ID\":");
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
                size_t taskPostion = line.find("\"Task Name\":");

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

        bool json::parse::isIDExist(int taskID)
        {
            std::fstream file(json::parse::fileName);
            std::string line;
            
            while(std::getline(file, line))
            {
                size_t IDPostion = line.find("\"ID\":");
                if(IDPostion != std::string::npos)
                {
                    int currentID = 0;
                    std::stringstream ID(line.substr(IDPostion + 5));
                    ID >> currentID;

                    if(currentID == taskID){ return true;}
                }
            }
            file.close();
            return false;
        }


        void json::parse::deleteTask(int taskID)
        {
            std::ifstream inFile(json::parse::fileName);
            std::string fileContent, line;
            while (std::getline(inFile, line)) {fileContent += line + "\n"; }

            inFile.close();
            fileContent = fileContent.substr(1, fileContent.size() - 2);

            std::stringstream newContent;
            newContent << "[\n";
            bool first = true;

            size_t pos = 0;
            while (pos < fileContent.size())
            {
                size_t start = fileContent.find("{", pos);
                if (start == std::string::npos) break;

                size_t end = fileContent.find("}", start);
                std::string task = fileContent.substr(start, end - start + 1);

                size_t IDpostion = task.find("\"ID\":");
               
                    int currentID = std::stoi(task.substr(IDpostion + 5));
                    if (currentID == taskID)
                    {
                        pos = end + 1; 
                        continue;
                    }
                
                if (!first)
                {
                    newContent << ",\n";
                }
                newContent << "\t" << task; 
                first = false;

                pos = end + 1;
            }

            newContent << "\n]";
            std::ofstream outFile(json::parse::fileName);
            outFile << newContent.str();
            outFile.close();
        }



        std::vector<std::string> json::parse::loadFileToVector()
        {
            std::ifstream file(json::parse::fileName);
            std::vector<std::string> convertedFile;
            std::string line;

            while(std::getline(file, line)){ convertedFile.push_back(line);}
            file.close();
            return convertedFile;
        }


        void json::parse::displayTaskList() 
        {
            std::ifstream file(json::parse::fileName);
            std::string line;
            while(std::getline(file, line))
            {
                std::cout << line << '\n';
            }
        }

        void json::parse::updateTask(std::string const& argument, int taskID)
         {
                std::vector<std::string> taskJSONFile = json::parse::loadFileToVector();


                for(int i = 0; i < taskJSONFile.size(); i++)
                {
                      if (taskJSONFile[i].find("\"ID\": " + std::to_string(taskID)) != std::string::npos)
                      {
                        taskJSONFile[i + 1] = "        \"Task Name\": \"" + argument + "\",";
                         taskJSONFile[i + 4] = "        \"Updated at\": \"" + Utility::Helper::getCurrentTime() + "\",";
                        break; 
                     }
                }
                
                std::ofstream ofile(json::parse::fileName);
                for(auto const& content: taskJSONFile)
                {
                    ofile << content << '\n';
                }
                ofile.close();
         }


         void json::parse::markpTask(std::string const& argument, int taskID)
         {
                std::vector<std::string> taskJSONFile = json::parse::loadFileToVector();

                for(int i = 0; i < taskJSONFile.size(); i++)
                {
                      if (taskJSONFile[i].find("\"ID\": " + std::to_string(taskID)) != std::string::npos)
                      {
                         taskJSONFile[i + 4] = "        \"Updated at\": \"" + Utility::Helper::getCurrentTime() + "\",";
                         taskJSONFile[i + 5] = "        \"Status\": \"""In-Progress""\"";
                        break; 
                     }
                }
                
                std::ofstream ofile(json::parse::fileName);
                for(auto const& content: taskJSONFile)
                {
                    ofile << content << '\n';
                }
                ofile.close();
         }

         void json::parse::markdTask(std::string const& argument, int taskID)
         {
            std::vector<std::string> taskJSONFile = json::parse::loadFileToVector();
                
                for(int i = 0; i < taskJSONFile.size(); i++)
                {
                      if (taskJSONFile[i].find("\"ID\": " + std::to_string(taskID)) != std::string::npos)
                      {
                         taskJSONFile[i + 4] = "        \"Updated at\": \"" + Utility::Helper::getCurrentTime() + "\",";
                         taskJSONFile[i + 5] = "        \"Status\": \"""Completed""\"";
                        break; 
                     }
                }
                
                std::ofstream ofile(json::parse::fileName);
                for(auto const& content: taskJSONFile)
                {
                    ofile << content << '\n';
                }
                ofile.close();
         }


         void json::parse::displayCompletedTasks()
         {
            
         }


    }

