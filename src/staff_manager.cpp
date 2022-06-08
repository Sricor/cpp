#include "staff_manager.h"

StaffManager::StaffManager()
{

}

void StaffManager::showMenu()
{
    std::cout << std::endl;;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "-----         Welcome to Employee Management System       -----" << std::endl;
    std::cout << "-----      1: Add Employee Information                    -----" << std::endl;
    std::cout << "-----      2: View Employee Information                   -----" << std::endl;
    std::cout << "-----      3: Remove Employee Information                 -----" << std::endl;
    std::cout << "-----      4: Modify Employee Information                 -----" << std::endl;
    std::cout << "-----      5: Search Employee Information                 -----" << std::endl;
    std::cout << "-----      6: Sort Employee Information By Employee ID    -----" << std::endl;
    std::cout << "-----      7: Remove All Employee Information             -----" << std::endl;
    std::cout << "-----      0: Exit                                        -----" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void StaffManager::saveFile()
{
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out);
    
    for (int i = 0; i < this->staff_num; i++)
    {
        ofs << this->staff_arr[i]->staff_id << " "
            << this->staff_arr[i]->staff_name << " "
            << this->staff_arr[i]->staff_position << " ";
        ofs << std::endl;
    }

    ofs.close();
}

void StaffManager::addStaff()
{
    int addNum = 0;
    std::cout << "Please enter add staff number: "; 
    std::cin  >> addNum; std::cout << std::endl;
    if (addNum <= 0){ return; }

    int newStaffNum = this->staff_num + addNum;
    Staff **newStaffArr = new Staff *[newStaffNum];

    // 将原有员工添加
    if (this->staff_arr != NULL)
    {
        for (int i = 0; i < this->staff_num; i++)
        {
            newStaffArr[i] = this->staff_arr[i];
        }
    }

    // 添加员工
    for (int i = 0; i < addNum; i++)
    {
        int id;
        int position;
        std::string name;
        Staff *p = NULL;
        
        std::cout << "Plase enter the " << i + 1 << " staff id: ";
        std::cin  >> id;

        std::cout << "Plase enter the " << i + 1 << " staff name: ";
        std::cin  >> name;

        std::cout << "Plase enter the " << i + 1 << " staff position ";
        std::cout << "1: Normal  2: Manager  3: Boss : ";
        std::cin  >> position;
        std::cout << std::endl;

        switch (position)
        {
        case 1:  p = new NormalStaff(id, name);  break;
        case 2:  p = new ManagerStaff(id, name); break;
        case 3:  p = new BossStaff(id, name);    break;
        default: break;
        }
        newStaffArr[this->staff_num + i] = p;
        // delete p;        // 测试代码 后面修改
    }

    for (int i = 0; i < addNum; i++)
    {
        newStaffArr[this->staff_num + i]->showInfo();
    }
    std::cout << std::endl;
    
    delete [] this->staff_arr;                // 删除原指针数组
    this->staff_arr = newStaffArr;            // 新数组
    this->staff_num = newStaffNum;            // 新员工人数
    this->saveFile();                         // 保存数据到文件
    
    std::cout << "Add staff success " << std::endl;
}

void StaffManager::exitSystem()
{
    exit(0);
}

StaffManager::~StaffManager()
{
    if (this->staff_arr != NULL)
    {
        delete[] this->staff_arr;
        this->staff_arr = NULL;
    }
    
}