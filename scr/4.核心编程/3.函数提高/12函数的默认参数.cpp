#include<iostream>
using namespace std;

int func(int a, int b = 10, int c = 30)// 已经有默认参数的位置往后,均需要给定默认参数
{
    return a + b + c;
}

// 函数声明和函数实现只能有一个给定默认参数
int func2(int a = 10, int b = 10);

int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << func(10) << endl;
    cout << func(10, 20) << endl;
    cout << func(10, 20, 50) << endl;

    cout << func2(20, 30) << endl;
}