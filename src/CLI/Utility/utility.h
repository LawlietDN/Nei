#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "taskData.h"

namespace Utility
{
    class Helper
    {
  
    public:
         static std::vector<std::pair<std::string, std::string>> setCommandsVariable();
         static std::string setExtraInfoVariable();
         static int displayHelpCommand();
         static void InvalidIDmessage(std::ostream& os);
         static std::string getCurrentTime();
         static void displayTaskExistsMessage(std::ostream& os);
    };
}
