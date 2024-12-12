#include "Task/task.h"
#include "Task Management/taskManger.h"


int main(int argc, char* argv[])
{
    util::TaskManager run;
    run.manageTaskArguments(argc, argv);
    return 0;
}   