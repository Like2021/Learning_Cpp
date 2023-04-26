#include<iostream>
using namespace std;

void mySwap(int a, int b)  // 值传递,传进去的是值
{
    int temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
}

void mySwap02(int *a, int *b)  // 地址传递,形参会修饰实参
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << *a << endl;
    cout << *b << endl;
}

void mySwap03(int &a, int &b)  // 引用传递,形参会修饰实参
{
    // 传递过程是:int &a = a, int &b = b(取别名)
    int temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    mySwap(a, b);
    // mySwap02(&a, &b);
    // mySwap03(a, b);
    cout << a << endl;
    cout << b << endl;

    system("read -p 'Press Enter to continue...' var");
}