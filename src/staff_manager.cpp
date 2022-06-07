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

void StaffManager::exitSystem()
{
    exit(0);
}

StaffManager::~StaffManager()
{

}