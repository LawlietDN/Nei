#pragma once
#include "CLI/cli.h"
namespace util
{
    class TaskManager
    {
public:
    TaskManager();

     void manageTaskArguments(int argc, char* argv[]);
    };
}

