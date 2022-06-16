#include "admin-indentity.h"

AdminIdentity ::AdminIdentity()
{
    this->GetAdmAccount();
    this->GetStuAccount();
    this->GetTeaAccount();
}

AdminIdentity::~AdminIdentity()
{

}

void AdminIdentity::AddAdmAccount()
{
    std::string account, name, password;
    std::vector<std::string> v;

    auto &admin_account = this->m_admin_account_container;
    auto &ofs = this->m_ofs;

    std::cout << "Please enter account: ";  std::cin >> account;  
    std::cout << "Please enter name: ";     std::cin >> name;     
    std::cout << "Please enter password: "; std::cin >> password; 
    v.push_back(account);
    v.push_back(name);
    v.push_back(name);
    admin_account.push_back(v);

    v.clear();

    ofs.open(ADMINACCOUNTFILE, std::ios::out);
    for (auto i = admin_account.begin(); i != admin_account.end(); i++)
    {
        v = *i;
        for (auto j = v.begin(); j != v.end(); j++)
        {
            ofs << *j << " ";
        }
        ofs << std::endl;
    }
    ofs.close();

    std::cout << "Add admin account done. " << std::endl;
}

void AdminIdentity::AddStuAccount()
{
    std::string account, name, password;
    std::vector<std::string> v;

    auto &student_account = this->m_student_account_container;
    auto &ofs = this->m_ofs;

    std::cout << "Please enter account: ";  std::cin >> account;  
    std::cout << "Please enter name: ";     std::cin >> name;     
    std::cout << "Please enter password: "; std::cin >> password; 
    v.push_back(account);
    v.push_back(name);
    v.push_back(name);
    student_account.push_back(v);

    v.clear();

    ofs.open(STUACCOUNTFILE, std::ios::out);
    for (auto i = student_account.begin(); i != student_account.end(); i++)
    {
        v = *i;
        for (auto j = v.begin(); j != v.end(); j++)
        {
            ofs << *j << " ";
        }
        ofs << std::endl;
    }
    ofs.close();

    std::cout << "Add student account done. " << std::endl;
}

void AdminIdentity::AddTeaAccount()
{
    std::string account, name, password;
    std::vector<std::string> v;

    auto &teacher_account = this->m_teacher_account_container;
    auto &ofs = this->m_ofs;

    std::cout << "Please enter account: ";  std::cin >> account;  
    std::cout << "Please enter name: ";     std::cin >> name;     
    std::cout << "Please enter password: "; std::cin >> password; 
    v.push_back(account);
    v.push_back(name);
    v.push_back(name);
    teacher_account.push_back(v);

    v.clear();

    ofs.open(TEAACCOUNTFILE, std::ios::out);
    for (auto i = teacher_account.begin(); i != teacher_account.end(); i++)
    {
        v = *i;
        for (auto j = v.begin(); j != v.end(); j++)
        {
            ofs << *j << " ";
        }
        ofs << std::endl;
    }
    ofs.close();

    std::cout << "Add teacher account done. " << std::endl;
}

void AdminIdentity::GetAdmAccount()
{
    std::string account, name, password;
    auto &ifs = this->m_ifs;
    auto &admin_account = this->m_admin_account_container;

    std::vector<std::string> temp_container;

    ifs.open(ADMINACCOUNTFILE, std::ios::in);
    while(!ifs.eof())
    {
        ifs >> account;  temp_container.push_back(account);
        ifs >> name;     temp_container.push_back(name);
        ifs >> password; temp_container.push_back(password);

        admin_account.push_back(temp_container);
        temp_container.clear();
    }
    ifs.close();
}

void AdminIdentity::GetStuAccount()
{
    std::string account, name, password;
    auto &ifs = this->m_ifs;
    auto &student_account = this->m_student_account_container;

    std::vector<std::string> temp_container;

    ifs.open(STUACCOUNTFILE, std::ios::in);
    while(!ifs.eof())
    {
        ifs >> account;  temp_container.push_back(account);
        ifs >> name;     temp_container.push_back(name);
        ifs >> password; temp_container.push_back(password);

        student_account.push_back(temp_container);
        temp_container.clear();
    }
    ifs.close();
}

void AdminIdentity::GetTeaAccount()
{
    std::string account, name, password;
    auto &ifs = this->m_ifs;
    auto &teacher_account = this->m_teacher_account_container;

    std::vector<std::string> temp_container;

    ifs.open(TEAACCOUNTFILE, std::ios::in);
    while(!ifs.eof())
    {
        ifs >> account;  temp_container.push_back(account);
        ifs >> name;     temp_container.push_back(name);
        ifs >> password; temp_container.push_back(password);

        teacher_account.push_back(temp_container);
        temp_container.clear();
    }
    ifs.close();
}

void AdminIdentity::ViewAdmAccount()
{
    auto &admin_account = this->m_admin_account_container;

    for (auto it = admin_account.begin(); it != admin_account.end(); it++)
    {
        std::cout << "Admin Account: " << it->at(0) << " Name: " << it->at(1) << " Password: " << it->at(2) << std::endl;
    } 
}

void AdminIdentity::ViewStuAccount()
{
    auto &student_account = this->m_student_account_container;

    for (auto it = student_account.begin(); it != student_account.end(); it++)
    {
        std::cout << "Student Account: " << it->at(0) << " Name: " << it->at(1) << " Password: " << it->at(2) << std::endl;
    } 
}

void AdminIdentity::ViewTeaAccount()
{
    auto &teacher_account = this->m_teacher_account_container;

    for (auto it = teacher_account.begin(); it != teacher_account.end(); it++)
    {
        std::cout << "Teacher Account: " << it->at(0) << " Name: " << it->at(1) << " Password: " << it->at(2) << std::endl;
    } 
} 

bool AdminIdentity::SignIn()
{
    std::string temp_account;
    std::string temp_password;
    auto &admin_account = this->m_admin_account_container;

    std::cout << "Plase enter your account: ";
    std::cin  >> temp_account;

    for (int i = 0; i < admin_account.size(); i++)
    {
        if (admin_account[i][0] == temp_account)
        {
            std::cout << "Plase enter your password: ";
            std::cin  >> temp_password;
            std::cout << std::endl;

            if (admin_account[i][2] == temp_password)
            {
                this->m_name = admin_account[i][1];
                return true;
            }
        }
    }
    std::cout << "Account not found" << std::endl;
    return false;
}