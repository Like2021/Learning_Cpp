#include<iostream>
using namespace std;

// 继承方式

// 父类
class Base1
{
    public:
    int m_A;

    protected:
    int m_B;

    private:
    int m_C;
};

// 子类
class Son1 : public Base1
{
    public:
    void func()
    {
        // public protected 子类用public继承都能访问
        m_A = 10;
        m_B = 20;
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 200;
    // s1.m_B = 200  // 保护权限，类外无法访问
}

// 保护继承
class Son2 : protected Base1
{
    public:
    void func()
    {
        // public protected 子类用public继承都能访问
        m_A = 10;
        m_B = 20;
    }
};

void test02()
{
    Son2 s2;
    // s2.m_A = 200;  // 由于保护继承之后，公共属性变成了保护属性，因此类外无法访问
}

// 私有继承
class Son3 : private Base1
{
    public:
    void func()
    {
        m_A = 100;
        m_B = 200;
    }
};

void test03()
{
    Son3 s3;
    // s3.m_A = 200;  // 由于私有继承之后，变为了私有属性，因此类外无法访问
}

class GrandSon3 : public Son3
{
    public:
    void func()
    {
        // m_A = 100;  //  公告属性在Son3中变成了私有，无法继承
    }
};

int main()
{
    // test01();
    // test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}