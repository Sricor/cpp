// 利用函数模板封装一个排序的函数，可以对 不同数据类型 进行排序

#include <iostream>

// 交换元素 函数模板
template <class T>
void exchangeVal(T &val1, T &val2)
{
    T temp = val1;
    val1 = val2;   
    val2 = temp;
}

// 冒泡排序 函数模板
template <class T>
void sortArr(T &arr, int arrLen)
{
    for (int i = 0; i < arrLen - 1; i++)
    {
        for (int j = 0; j < arrLen - i - 1; j++)
        {
            if (arr[j] > arr[ j + 1 ])
            {
                exchangeVal(arr[j], arr[j+1]);
            }
        }
    }
}

// 打印数组 函数模板
template<class T>
void printArr(T arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
       std::cout << arr[i];
    }
    std::cout << std::endl;
}

// 整型排序测试
void sortIntArrTest()
{
    int arr[9] = {1, 3, 2, 4, 6, 5, 8, 7, 0};
    printArr(arr, 9);

    sortArr(arr, 9);
    printArr(arr, 9);
}

// 字符型排序测试
void sortCharArrTest()
{
    char arr[9] = "ajbsczlq";
    printArr(arr, 9);

    sortArr(arr, 9);
    printArr(arr, 9);
}

int main()
{
    sortIntArrTest();

    sortCharArrTest();

    system("pause");
    return 0;
}