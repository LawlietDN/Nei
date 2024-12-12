#include "taskManger.h"

namespace util
{
    util::TaskManager::TaskManager()
    {

    }
    void util::TaskManager::manageTaskArguments(int argc, char* argv[])
    {
        cli::ArgumentParse parser;
        std::vector<std::string> arguments = parser.passArgument(argc, argv);
        std::cout << "Arguments: " << argc << '\n';
        for(int i = 0; i < argc; i++)
        {
           std::cout << "\nArgument " << i << ": " << argv[i] << '\n';
        }
    }
}
