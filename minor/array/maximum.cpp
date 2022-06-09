// 数组元素最值
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = { 300, 350, 200, 400, 250};   // 原数组
    int max = arr[0];                          // 最大值
    int min = arr[0];                          // 最小值

    for (int i = 0; i < 5; i++) 
    {
        if (max < arr[i]) max = arr[i]; // 最大值替换
        if (min > arr[i]) min = arr[i]; // 最小值替换
    }

    cout << max << endl;
    cout << min << endl;
    
    return 0;
}