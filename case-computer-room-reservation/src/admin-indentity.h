#pragma once
#include "base-identity.h"

class AdminIdentity :public BaseIdentity
{
public:
    AdminIdentity ();
    ~AdminIdentity ();

    bool SignIn();
    //void ViewRoom ();          // 查看机房
    //void RemoveReservation();  // 清空预约

    void AddAdmAccount();
    void AddStuAccount();
    void AddTeaAccount();

    void ViewAdmAccount();
    void ViewStuAccount();
    void ViewTeaAccount();
    
protected:
    void GetAdmAccount();
    void GetStuAccount();
    void GetTeaAccount();
};
