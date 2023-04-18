#include<iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base::func()" << endl;
    }

    void func(int a)
    {
        cout << "Base::func(int a)" << endl;
    }

    int m_A;
};

class Son1 : public Base
{
    public:
    Son1()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "Son1::func()" << endl;
    }

    int m_A;
};

void test01()
{
    Son1 s;
    cout << "m_A = " << s.m_A << endl;

    // 通过子类对象，访问父类成员属性，需要加上作用域
    cout << "m_A = " << s.Base::m_A << endl;
}

void test02()
{
    Son1 s;
    s.func();

    // 如果子类中出现和父类同名的成员函数，父类的成员函数（包括父类本身的同名函数）会被隐藏
    // 调用父类同名函数，需要作用域
    s.Base::func();
    s.Base::func(100);
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}