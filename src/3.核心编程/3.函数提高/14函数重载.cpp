#include<iostream>
using namespace std;

// 函数名可以相同,提高复用性
// 函数的返回类型不可以作为函数的重载条件

void func()
{
    cout << "using func" << endl;
}

// 重载的条件
// 1.同一个作用域下
// 2.函数名相同
// 3.函数参数类型不同,或者个数不同,或者顺序不同(多个参数不同顺序)

void func(int a)
{
    cout << "using int a." << endl;
}

void func(double a)
{
    cout << "using double a." << endl;
}

int main()
{
    // 根据不同的传参,调用不同的函数
    func();
    func(10);
    func(3.14);
}