#pragma once
#include <iostream>
#include "staff.h"

class ManagerStaff :public Staff
{
public:
    ManagerStaff(int id, std::string name);
    virtual ~ManagerStaff();
    virtual void showInfo();
};
