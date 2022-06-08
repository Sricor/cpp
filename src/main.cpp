#include <iostream>
#include "staff_manager.h"
using namespace std;

#include "staff.h"
#include "normal_staff.h"
#include "manager_staff.h"
#include "boss_staff.h"

void test()
{
    StaffManager sm;
    int comd = 0;
    while (true)
    {
        sm.showMenu();
        cin >> comd;
        cout << endl;;
        switch (comd)
        {
        default: break;
        case 0: sm.exitSystem(); break;
        case 1: sm.addStaff();   break;
        case 2: sm.viewStaff();  break;
        }
    }
}

int main()
{
    test();
    return 0;
}