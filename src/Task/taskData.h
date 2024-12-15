#pragma once
#include <string>
#include <vector>


struct TaskData {
    int taskID;
    int deleteID;
    std::string task;
    std::string description;
    std::string status;
    std::string createdAt;
    std::string updatedAt;
};

