#include <iostream>
#include "staff_manager.h"
using namespace std;

#include "staff.h"
#include "normal_staff.h"
#include "manager_staff.h"
#include "boss_staff.h"

void test()
{
    
/*     Staff *p;
    p = new NormalStaff(1, "Hello");
    p->showInfo(); */


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
        case 0: sm.exitSystem();
        case 1: sm.addStaff();
        }
    }
}

int main()
{
    test();
    return 0;
}