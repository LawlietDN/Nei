#include <string>
#pragma once

namespace manage
{
    class task
    {
private:
        int id;
        std::string description;
        std::string status;
        std::string createdAt;
        std::string updatedAt;
    };
}