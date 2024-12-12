#pragma once
#include <vector>
#include <string>
#include <iostream>
namespace Utility
{
    class Helper
    {
  
    public:
         static std::vector<std::pair<std::string, std::string>> setCommandsVariable();
         static std::string setExtraInfoVariable();
         static int displayHelpCommand();

    };
}
