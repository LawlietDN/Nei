#include "taskData.h"


//remove this.
struct TaskData {
    int taskID;
    std::string task;
    std::string description;
    std::string status;
    std::string createdAt;
    std::string updatedAt;
    std::vector<std::string> taskList;
};
