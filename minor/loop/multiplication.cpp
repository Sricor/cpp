// 9 x 9 乘法表
#include <iostream>
using namespace std;

int main()
{
    int num = 9;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
            cout <<  j << " x " << i << " = " << j * i << "  ";
        cout << endl;
    }
    
    return 0;
}