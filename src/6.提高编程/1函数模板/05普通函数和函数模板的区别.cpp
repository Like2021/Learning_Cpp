#include<iostream>
using namespace std;

// 1.普通函数调用可以发生隐式类型转换
// 2.函数模板用自动类型推导 不可发生
// 3.用显示指定 可以发生

// 普通函数
int myAdd01(int a, int b)
{
    return a + b;
}

// 函数模板
template<class T>
T myAdd02(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10; 
    int b = 20;

    char c = 'c';  // a - 97; c - 99
    cout << myAdd01(a, c) << endl;

    // 自动类型推导
    cout << myAdd02(a, b) << endl;

    // 显示指定类型
    cout << myAdd02<char>(a, c) << endl;
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}