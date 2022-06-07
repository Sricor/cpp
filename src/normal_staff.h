#pragma once
#include <iostream>
#include "staff.h"

class NormalStaff :public Staff
{
public:
    NormalStaff(int id, std::string name);
    virtual ~NormalStaff();
    virtual void showInfo();
};
