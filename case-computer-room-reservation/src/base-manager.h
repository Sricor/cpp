#pragma once

#include <iostream>
#include<algorithm>

// 管理功能类
class BaseManager
{
public:
    BaseManager(){};
    virtual ~BaseManager(){};
    virtual void Menu(){};
};