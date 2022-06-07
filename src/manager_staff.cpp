#include "manager_staff.h"

ManagerStaff::ManagerStaff(int id, std::string name)
{
    this->staff_id = id;
    this->staff_name = name;
    this->staff_position = 1;
}

void ManagerStaff::showInfo()
{
    std::cout << "Staff ID: "   << this->staff_id
              << " Name: "      << this->staff_name
              << " Position: "  << "Manager" 
              << std::endl;
}

ManagerStaff::~ManagerStaff()
{
    
}
