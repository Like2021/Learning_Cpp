#include<iostream>
using namespace std;



void test01()
{
    // 将a和b做比较，将变量大的赋值给变量c
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);  // 如果满足a>b返回变量a，否则返回变量b
    cout << "c = " << c << endl;

    // 在C++中三目运算符返回的是变量，可以继续赋值
    (a > b ? a : b) = 100;  // 返回变量b，并给其赋值100
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}