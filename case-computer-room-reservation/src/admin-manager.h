#pragma once

#include "base-manager.h"
#include "admin-indentity.h"

class AdminManager :public BaseManager
{
protected:
    AdminIdentity m_admin_identity;

    void AddAccount();
    void ViewAccount();
    
public:
    AdminManager();
    virtual ~AdminManager();
    virtual void Menu();
};

