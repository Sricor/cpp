// 数组元素排序
// 冒泡排序
#include <iostream>
using namespace std;

int main()
{
    int arr[9] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
    
    // 开始冒泡排序
    // 轮数 =  元素个数 - 1
    for (int i = 0; i < 9 - 1; i++)
    {
        // 内层循环对比 轮数 = 元素个数 - 当前轮数 - 1
        for (int j = 0; j < 9 - i - 1; j++)
        {
            // 如果第一个数字比第二个数字大，交换两个数字 大小符号决定升降序
            if (arr[j] > arr[ j + 1 ])
            {
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[ j + 1 ];
                arr[j + 1] = temp;
            }
        }
    }

    // 打印输出
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}