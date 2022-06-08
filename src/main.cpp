#include <iostream>
#include "staff_manager.h"
using namespace std;

void test()
{
    StaffManager sm;    // 实例化员工管理系统
    int comd = 0;
    while (true)
    {
        sm.showMenu();  // 菜单
        cin >> comd;    // 获取输入
        cout << endl;; 
        switch (comd)
        {
        default: break;
        case 0: sm.exitSystem();  break;   // 退出
        case 1: sm.addStaff();    break;   // 添加员工
        case 2: sm.viewStaff();   break;   // 查看员工
        case 3: sm.removeStaff(); break;   // 删除员工
        case 4: sm.modifyStaff(); break;   // 修改员工
        }
    }
}

int main()
{
    test();
    return 0;
}