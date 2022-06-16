#pragma once

#include "admin-manager.h"

class Reservation
{
private:
    BaseManager *p_manger;          // 菜单指针

protected:
    //void StudentIdentityManager();  // 学生菜单
    //void TeacherIdentityManager();  // 老师菜单
    void AdminIdentityManager();    // 管理员菜单

public:
    Reservation();
    virtual ~Reservation();
    virtual void ReservationManager();
};
