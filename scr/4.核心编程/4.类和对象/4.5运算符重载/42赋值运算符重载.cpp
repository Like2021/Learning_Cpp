#include<iostream>
using namespace std;

// 赋值运算符重载

// 涉及到深浅拷贝

class Person
{
    public:

    Person (int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载赋值运算符
    Person& operator=(Person &p)
    {
        // 浅拷贝
        // m_Age = p.m_Age;

        // 应该判断本身是否有属性在堆区，有的话需要先释放
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        // 深拷贝操作
        m_Age = new int(*p.m_Age);

        // 利用this解引用返回对象自身,以实现链式应用
        return *this;
    }

    int *m_Age;
};

void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    // p2 = p1;  // 不重载赋值运算符，这两个对象里的m_Age都是同一个指针，指向堆区的同一块数据

    p3 = p2 = p1;  // 链式应用

    cout << *p3.m_Age << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}