#pragma once
#include <iostream>

#include "staff.h"
#include "normal_staff.h"
#include "manager_staff.h"
#include "boss_staff.h"

class StaffManager
{
public:
    StaffManager();
    void showMenu();           // 展示菜单
    void exitSystem();         // 退出系统
    virtual ~StaffManager();
};