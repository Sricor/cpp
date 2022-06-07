#include "normal_staff.h"

NormalStaff::NormalStaff(int id, std::string name)
{
    this->staff_id = id;
    this->staff_name = name;
    this->staff_position = 1;
}

void NormalStaff::showInfo()
{
    std::cout << "Staff ID: "   << this->staff_id
              << " Name: "      << this->staff_name
              << " Position: "  << "Normal" 
              << std::endl;
}

NormalStaff::~NormalStaff()
{
    
}
