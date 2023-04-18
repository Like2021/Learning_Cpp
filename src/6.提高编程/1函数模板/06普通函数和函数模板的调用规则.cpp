#include<iostream>
using namespace std;

// 如果都可以调用，则优先调用普通函数
// 可以通过空模板参数列表，强制调用 函数模板
// 函数模板也可以发生函数重载
// 如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b)
{
    cout << "普通函数调用" << endl;
}

template<class T>
void myPrint(T a, T b)
{
    cout << "函数模板调用" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
    cout << "重载函数模板调用" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    myPrint(a, b);

    // 通过空模板的参数列表，强制调用函数模板
    myPrint<>(a, b);

    myPrint(a, b, 100);

    // 如果函数模板产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';

    myPrint(c1, c2);
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}