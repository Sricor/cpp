#include "staff_manager.h"

StaffManager::StaffManager()
{
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    // 文件不存在 初始化属性
    if ( !ifs.is_open() )
    {
        this->staff_num = 0;      // 员工数
        this->staff_arr = NULL;   // 空指针
        this->file_real = false;  // 文件为假
        
        ifs.close();
        return;
    }
    
    // 文件存在 数据为空 初始化属性
    char ch;
    ifs >> ch;
    if ( ifs.eof() )
    {
        this->staff_num = 0;      // 员工数
        this->staff_arr = NULL;   // 空指针
        this->file_real = false;  // 文件为假

        ifs.close();
        return;
    }

    // 文件存在 数据存在 初始化属性
    this->initStaff();
    ifs.close();

    
    
    return;

    std::cout << this->isStaffExist(1) << std::endl;  // 测试员工是否存在

    // 初始化测试代码
    for (int i = 0; i < this->staff_num; i++)
    {
        std::cout << "Staff ID: "  << this->staff_arr[i]->staff_id
                  << " Name: "     << this->staff_arr[i]->staff_name
                  << " Position: " << this->staff_arr[i]->staff_position;
        std::cout << std::endl;
    }
    
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

void StaffManager::initStaff()
{
    int num = 0;       // 统计员工数
    int index = 0;     // 数组索引值
    int id, position;  // ID, 岗位编号
    std::string name;  // 员工姓名
    std::ifstream ifs;

    ifs.open(FILENAME, std::ios::in);
    while (ifs >> id && ifs >> name && ifs >> position) {num++;}   // 统计人数
    ifs.close();

    this->file_real = true;              // 文件存在
    this->staff_num = num;               // 初始化 员工人数
    this->staff_arr = new Staff*[num];   // 以新人数 开辟指针数组空间

    // 初始化 指针数组
    ifs.open(FILENAME, std::ios::in);
    while (ifs >> id && ifs >> name && ifs >> position)
    {
        Staff *p = NULL;
        if      (position == 1) { p = new NormalStaff(id, name); }   // 普通
        else if (position == 2) { p = new ManagerStaff(id, name); }  // 经理
        else if (position == 3) { p = new BossStaff(id, name); }     // 老板

        this->staff_arr[index] = p;  // 存放指针数组
        index++;
    }
    ifs.close();

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

int StaffManager::isStaffExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->staff_num; i++)
    {
       if (this->staff_arr[i]->staff_id == id)
       {
           index = i;
           break;
       }
    }
    return index;
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
    this->file_real = true;                   // 文件为真
    this->saveFile();                         // 保存数据到文件

    std::cout << "Add staff success " << std::endl;
}

void StaffManager::viewStaff()
{
    if (!this->file_real){ std::cout << FILENAME <<"File not found or content is empty" << std::endl; }  // 文件为空
    else
    {
        for (int i = 0; i < this->staff_num; i++)
        {
            this->staff_arr[i]->showInfo(); // 查看员工信息
        }
    }
}

void StaffManager::removeStaff()
{
    int id = 0;
    int index = 0;
    if (!this->file_real){ std::cout << FILENAME <<"File not found or content is empty" << std::endl; }  // 文件为空
    else
    {
        std::cout << "Please enter staff ID to remove: ";
        std::cin  >> id;
        index = this->isStaffExist(id); // 获取待删除员工编号所在的下标
        if (index == -1) { std::cout << "Remove staff error, staff id not found" << std::endl;}
        else
        {
            for (int i = index; i < this->staff_num - 1; i++)
            {
               this->staff_arr[i] = this->staff_arr[i + 1]; // 数组前移
            }
            this->staff_num--; // 更新员工数
            this->saveFile();  // 保存数据至文件

            std::cout << "Remove staff succes " << std::endl;
        }
    }
}

void StaffManager::modifyStaff()
{
    int id = 0;
    int index = 0;
    if (!this->file_real){ std::cout << FILENAME <<"File not found or content is empty" << std::endl; }  // 文件为空
    else
    {
        std::cout << "Please enter staff ID to modify: ";
        std::cin  >> id;
        index = this->isStaffExist(id);     // 获取待修改员工编号所在的下标
        if (index == -1) { std::cout << "Modify staff error, staff id not found" << std::endl;}
        else
        {
            delete this->staff_arr[index];
            
            int newID = 0;
            int newPosition = 1;
            std::string newName = "";
            Staff *p = NULL;

            std::cout << "Plase enter the new staff id: ";
            std::cin  >> newID;

            std::cout << "Plase enter the  new  staff name: ";
            std::cin  >> newName;

            std::cout << "Plase enter the new staff position ";
            std::cout << "1: Normal  2: Manager  3: Boss : ";
            std::cin  >> newPosition;
            std::cout << std::endl;

            switch (newPosition)
            {
            case 1:  p = new NormalStaff(newID, newName);  break;
            case 2:  p = new ManagerStaff(newID, newName); break;
            case 3:  p = new BossStaff(newID, newName);    break;
            default: break;
            }

            this->staff_arr[index] = p;    // 更新数据
            this->saveFile();              // 保存数据
            std::cout << "Modify staff succes " << std::endl;
        }
    }
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