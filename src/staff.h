#pragma once
#include <iostream>

class Staff
{
public:
    int staff_id;
    int staff_position;
    std::string staff_name;

    Staff();
    virtual ~Staff();
    virtual void showInfo();
};
