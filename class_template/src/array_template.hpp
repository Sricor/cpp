#pragma once
#include <iostream>

template <class T>
class ArrayTemplate
{
private:
    int array_len;        // 数组长度(元素个数)
    int array_capacity;   // 数组容量(数组长度)
    T   *array_adress;    // 接收数组指针
public:
    ArrayTemplate(int capacity);             // 有参构造
    ArrayTemplate(const ArrayTemplate &o);   // 拷贝构造
    ~ArrayTemplate();                        // 析构
    ArrayTemplate& operator=(const ArrayTemplate &o);  // 重载赋值
    T& operator[](int index);                // 重载下标
    void pushBack(const T &val);             // 尾插法
    void popBack();                          // 尾删法
    int getCapacity();                       // 获取容量
    int getLen();                            // 获取长度 
};


// 有参构造
template <class T>
ArrayTemplate<T>::ArrayTemplate(int capacity)
{
    // std::cout << "ArrayTemplate()" << std::endl;
    this->array_len = 0;                               // 初始化数组长度
    this->array_capacity = capacity;                   // 设定数组容量
    this->array_adress = new T[this->array_capacity];  // 以指定容量开辟空间
}

// 拷贝构造
template <class T>
ArrayTemplate<T>::ArrayTemplate(const ArrayTemplate &o)
{
    // std::cout << "ArrayTemplate() copy" << std::endl;
    this->array_len = o.array_len;
    this->array_capacity = o.array_capacity;
    // this->array_adress = o.array_adress;        // 浅拷贝
    this->array_adress = new T[o.array_capacity];  // 深拷贝
    
    // 拷贝原数组数据
    for (int i = 0; i < o.array_len; i++)
    {
        this->array_adress[i] = o.array_adress[i];
    }
}

// 析构
template <class T>
ArrayTemplate<T>::~ArrayTemplate()
{
    // std::cout << "~ArrayTemplate()" << std::endl;
    if (this->array_adress != NULL)
    {
        delete[] this->array_adress;
        this->array_adress = NULL;
    }
}

// 重载赋值
template <class T>
ArrayTemplate<T>& ArrayTemplate<T>::operator=(const ArrayTemplate &o)
{
    // std::cout << "ArrayTemplate operator=()" << std::endl;

    if (this->array_adress != NULL)
    {
        delete[] this->array_adress;
        this->array_adress = NULL;
        this->array_capacity = 0;
        this->array_len = 0;
    }

    this->array_len = o.array_len;                  // 初始化数组长度
    this->array_capacity = o.array_capacity;        // 设定数组容量
    this->array_adress = new T[o.array_capacity];   // 以指定容量开辟空间

    for (int i = 0; i < o.array_len; i++)
    {
        this->array_adress[i] = o.array_adress[i];
    }

    return *this;
}

// 重载下标
template <class T>
T& ArrayTemplate<T>::operator[](int index)
{
    return this->array_adress[index];
}

// 尾插法 在末尾添加元素
template <class T>
void ArrayTemplate<T>::pushBack(const T &val)
{
    if (this->array_capacity == this->array_len) { return; } // 无剩余容量
    this->array_adress[this->array_len] = val;               // 在数组最后一位插入值
    this->array_len++;                                       // 更新长度
}

// 尾删法 删除最后元素
template <class T>
void ArrayTemplate<T>::popBack()
{
    if (this->array_len == 0) { return; } // 数组长度为空
    array_len--;                          // 更新长度 逻辑删除
}

// 获取容量
template <class T>
int ArrayTemplate<T>::getCapacity() {return this->array_capacity; }

// 获取长度 
template <class T>
int ArrayTemplate<T>::getLen() {return this->array_len; }

