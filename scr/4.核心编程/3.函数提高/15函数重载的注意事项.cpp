#include<iostream>
using namespace std;

// 1.引用作为重载的条件
// 参数类型不同
void func(int &a)
{
    cout << "using func(int &a)." << endl;
}

void func(const int &a)  // const 修饰 只读状态
{
    cout << "using func(const int &a)." << endl;
}

// 2.函数重载碰到默认参数
void func2(int a)
{
    cout << "using func2(int a)." << endl;
}

void func2(int a, int b = 10)
{
    cout << "using func2()." << endl;
}

int main ()
{
    const int a = 10;
    func(a);
    func(10);// int &a = 10;不合法 const int &a = 10;合法

    // func2(20);不合法,因为有默认参数,两个重载函数都能调用,有二义性
    func2(10, 20);
}