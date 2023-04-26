#include<iostream>
using namespace std;

// 不要返回局部变量的引用
// 局部变量存放在栈区

// 函数的调用可以作为左值
int& test01()
{
    int a = 10;
    return a;
}

int& test02()
{
    static int a = 10;// 静态变量,存放在全局区
    return a;// 返回的是a的引用  (int&) 
}

int main()
{
    // int &ref = test01();
    int &ref = test02();

    cout << ref << endl;

    test02() = 1000;// 用原名a去赋值

    cout << ref << endl;// 用别名ref去打印

    system("read -p 'Press Enter to continue...' var");
}