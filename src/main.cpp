#include "Task/task.h"
#include "CLI/cli.h"


int main(int argc, char* argv[])
{
    cli::ArgumentParse parser;

    parser.parseArguments(argc, argv);
    
    return 0;
}   
