#include "Task/taskData.h"
#include "Task Management/taskManager.h"


int main(int argc, char* argv[])
{
    util::TaskManager run;
    run.manageTaskArguments(argc, argv);
    return 0;
}   