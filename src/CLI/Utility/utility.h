#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
namespace Utility
{
    class Helper
    {
  
    public:
         static std::vector<std::pair<std::string, std::string>> setCommandsVariable();
         static std::string setExtraInfoVariable();
         static int displayHelpCommand();
         static void InvalidIDmessage(std::ostream& os);

    };
}
