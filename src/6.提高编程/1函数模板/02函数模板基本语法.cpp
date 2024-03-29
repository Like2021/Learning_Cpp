#include<iostream>
using namespace std;

// 交换两个整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 函数模板
template<typename T>  // 声明一个模板，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


void test01()
{
    int a = 10;
    int b = 20;
    // swapInt(a, b);

    // 利用函数模板进行交换
    // 两种方式使用
    // 1.自动类型推导
    // mySwap(a, b);

    // 2.显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;

    double c = 1.1;
    double d = 2.2;
    // swapDouble(c, d);
    cout << "c = " << c << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}