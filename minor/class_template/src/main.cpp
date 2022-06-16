#include <iostream>

#include "array_template.hpp"


// 打印数组
void printArr(ArrayTemplate<int> &arr)
{
    for (int i = 0; i < arr.getLen(); i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}


void test()
{
    ArrayTemplate<int> finit(10);
    ArrayTemplate<int> sinit(5);

    for (int i = 0; i < 5; i++)
    {
        sinit.pushBack(i);        // 尾插法添加元素
    }
    printArr(sinit);

    sinit.popBack();              // 尾删测试
    
    std::cout << sinit.getLen();  // 获取长度测试
    std::cout << std::endl;

    std::cout << sinit.getCapacity(); // 获取容量测试
    std::cout << std::endl;

    ArrayTemplate<int> a(finit);  // 拷贝测试
    sinit = finit;                // 赋值测试
}

int main()
{
    test();
    return 0;
}