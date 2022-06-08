#pragma once
#include <iostream>
#include <fstream>

#include "staff.h"
#include "normal_staff.h"
#include "manager_staff.h"
#include "boss_staff.h"

#define FILENAME "staff.txt"

class StaffManager
{
public:
    int staff_num;             // 员工数
    bool file_real;            // 判断文件
    Staff **staff_arr;         // 员工指针数组

    StaffManager();
    void showMenu();           // 展示菜单
    void initStaff();          // 初始化员工
    void saveFile();           // 保存文件
    void addStaff();           // 添加员工
    void viewStaff();          // 查看员工
    void exitSystem();         // 退出系统
    virtual ~StaffManager();
};