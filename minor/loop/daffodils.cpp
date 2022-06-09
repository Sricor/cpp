// 水仙花数
// 一个三位数，个十百位数三次幂之和为这个数，称为水仙花数

#include <iostream>
using namespace std;

int main ()
{
    int num = 100;
    do
    {
        int a = (num % 10) * (num % 10) * (num % 10);                 // 个位数
        int b = (num / 10 % 10) * (num / 10 % 10) * (num / 10 % 10);  // 十位数
        int c = (num / 100) * (num / 100) * (num / 100);              // 百位数
        
        if (a + b + c == num) 
            cout << num << endl; 
        num++;
    } while (num <= 999);
    
    return 0;
}