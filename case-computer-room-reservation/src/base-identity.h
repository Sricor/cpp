#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

#define ADMINACCOUNTFILE "admin-account.txt"
#define STUACCOUNTFILE "student-account.txt"
#define TEAACCOUNTFILE "teacher-account.txt"


// 身分类 基类
class BaseIdentity
{
protected:
    std::string m_password;  // 密码
    std::ofstream m_ofs;     // 写文件
    std::ifstream m_ifs;     // 读文件

    std::vector<std::vector<std::string>> m_admin_account_container;    // 管理员账号容器
    std::vector<std::vector<std::string>> m_student_account_container;  // 学生账号容器
    std::vector<std::vector<std::string>> m_teacher_account_container;  // 老师账号容器

public:
    std::string m_name;      // 姓名
    std::string m_account;   // 账号

    BaseIdentity(){};
    virtual ~BaseIdentity(){};
};