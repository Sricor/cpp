#pragma once
#include <iostream>
#include "staff.h"

class BossStaff :public Staff
{
public:
    BossStaff(int id, std::string name);
    virtual ~BossStaff();
    virtual void showInfo();
};
