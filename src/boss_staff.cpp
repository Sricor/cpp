#include "boss_staff.h"

BossStaff::BossStaff(int id, std::string name)
{
    this->staff_id = id;
    this->staff_name = name;
    this->staff_position = 3;
}

void BossStaff::showInfo()
{
    std::cout << "Staff ID: "   << this->staff_id
              << " Name: "      << this->staff_name
              << " Position: "  << "Boss " 
              << std::endl;
}

BossStaff::~BossStaff()
{
    
}