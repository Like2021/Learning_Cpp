#include<iostream>
using namespace std;

// 父类
class Base1
{
    public:

    Base1()
    {
        m_A = 100;
    }

    int m_A;
};

class Base2
{
    public:

    Base2()
    {
        m_A = 200;
    }

    int m_A;
};

class Son1 : public Base1, public Base2
{
    public:

    Son1()
    {
        m_C = 300;
        m_D = 400;
    }

    int m_C;
    int m_D;
};

void test01()
{
    Son1 s;

    cout << "size of Son1 = " << sizeof(Son1) << endl;

    // 当父类中出现同名成员，需要加作用域区分
    cout << "m_A = " << s.Base1::m_A << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}