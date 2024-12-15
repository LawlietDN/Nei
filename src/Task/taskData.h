#pragma once
#include <string>
#include <vector>


struct TaskData {
    int taskID = 0;
    std::string task;
    std::string description;
    std::string status;
    std::string createdAt;
    std::string updatedAt;
};

