#include<iostream>
using namespace std;

// 静态成员，类内声明，类外初始化
// 静态函数，只能访问静态成员

class Base
{
    public:

    static int m_A;

    static void func()
    {
        cout << "Base static func()"  << endl;
    }

    static void func(int a)
    {
        cout << "Base static func(int a)"  << endl;
    }
};

// 类外初始化
int Base::m_A = 100;

class Son : public Base
{
    public:
    
    static int m_A;

    static void func()
    {
        cout << "Son static func()" << endl;
    }
};

// 类外初始化
int Son::m_A = 200;

// 同名静态成员属性
void test01()
{
    // 1.通过对象访问
    Son s;
    cout << "Son::m_A = " << s.m_A << endl;
    cout << "Base::m_A = " << s.Base::m_A << endl;

    // 2.通过类名访问
    cout << "Son::m_A = " << Son::m_A << endl;

    // Son通过类名的方式访问，Base下的m_A
    cout << "Base::m_A = " << Son::Base::m_A << endl;
}

// 同名静态成员函数
// 和同名静态成员属性访问方法一致
void test02()
{
    // 1.通过对象访问
    Son s;
    s.func();
    s.Base::func();

    // 2.通过类名访问
    Son::func();
    Son::Base::func();
    Son::Base::func(100);
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}