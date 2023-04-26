#include<iostream>
using namespace std;

// 给变量起别名
// 数据类型 &别名 = 原名

// 引用必须先初始化
// 必须有等号:int &b = a;
// 不能int &b;

// 一旦初始化之后不能更改
// int &b = a之后 不能将b改为c的别名
// b = c  赋值操作，而不是更改引用

int main()
{
    int a = 10;
    int &b = a;
    b = 20;
    cout << a << endl;

    cout << &a << " " << &b << endl;  // 取a和b的地址是一样的

    system("read -p 'Press Enter to continue...' var");
}