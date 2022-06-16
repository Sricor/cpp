#include "admin-manager.h"

AdminManager::AdminManager()
{

}

AdminManager::~AdminManager()
{

}

void AdminManager::AddAccount()
{
    int comd;

    while (true)
    {
        std::cout << "          Add Account          " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        std::cout << "      |  1: Student      |     " << std::endl;
        std::cout << "      |  2: Teacher      |     " << std::endl;
        std::cout << "      |  3: Admin        |     " << std::endl;
        std::cout << "      |  0: Exit         |     " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        
        std::cout << "Please enter add account identity: "; 
        std::cin >> comd; std::cout << std::endl;
        switch (comd)
        {
        case 1: this->m_admin_identity.AddStuAccount(); break;
        case 2: this->m_admin_identity.AddTeaAccount(); break;
        case 3: this->m_admin_identity.AddAdmAccount(); break;
        case 0: return;
        default: break;
        }
    }
}

void AdminManager::ViewAccount()
{
    int comd;

    while (true)
    {
        std::cout << "         View Account          " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        std::cout << "      |  1: Student      |     " << std::endl;
        std::cout << "      |  2: Teacher      |     " << std::endl;
        std::cout << "      |  3: Admin        |     " << std::endl;
        std::cout << "      |  0: Exit         |     " << std::endl;
        std::cout << "       ------------------      " << std::endl;
        
        std::cout << "Please enter view account identity: "; 
        std::cin >> comd; std::cout << std::endl;
        switch (comd)
        {
        case 1: this->m_admin_identity.ViewStuAccount(); break;
        case 2: this->m_admin_identity.ViewTeaAccount(); break;
        case 3: this->m_admin_identity.ViewAdmAccount(); break;
        case 0: return;
        default: break;
        }
    }
}


void AdminManager::Menu()
{
    int comd;
    if (!this->m_admin_identity.SignIn()) { return; } // 登录失败

    while (true)
    {
        std::cout << std::endl;
        std::cout << "             Manager Menu             " << std::endl;
        std::cout << "       -------------------------      " << std::endl;
        std::cout << "      |  1: Add Account         |     " << std::endl;
        std::cout << "      |  2: View Account        |     " << std::endl;
        std::cout << "      |  3: View Room           |     " << std::endl;
        std::cout << "      |  4: Remove reservation  |     " << std::endl;
        std::cout << "      |  0: Sign out            |     " << std::endl;
        std::cout << "       -------------------------      " << std::endl;
        std::cout << std::endl;

        std::cout << "Welcome: "<<  this->m_admin_identity.m_name << std::endl;
        std::cout << "Please select your operate: ";
        std::cin  >> comd; std::cout << std::endl;

        switch (comd)
        {
        case 0:  return;
        case 1:  this->AddAccount();  break;
        case 2:  this->ViewAccount(); break;
        default: break;
        }
    }
}
