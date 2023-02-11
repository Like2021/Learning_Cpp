#include<iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Person
{
    public:

    static void func()
    {
        m_A = 100;
        cout << "静态成员函数的调用" << endl;
    }

    static int m_A;  // 静态成员函数只能访问这个
    int m_B;

    // 静态成员函数也是有访问权限的,加上public才可以类外访问
    
};

int Person::m_A = 0;

void test01()
{
    // 1.通过对象访问
    Person p;
    p.func();

    // 2.通过类名访问
    Person::func();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}