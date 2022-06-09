// 数组元素逆置
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = { 1, 3, 2, 5, 4 };               // 原数组
    int start = 0;                                // 起始下标
    int end = 5 - 1;                              // 结束下标 元素个数 - 1 

    while (start < end) // 起始 < 结束 开始循环
    {
        // 元素互换
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // 下标更新
        start++;
        end--;
    }

    for (int i = 0; i < 5; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}