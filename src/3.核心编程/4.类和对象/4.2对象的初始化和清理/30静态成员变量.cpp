#include<iostream>
using namespace std;

// 静态成员就是成员函数和成员变量前加上static

class Person
{
    public:

    // 静态成员变量
    // 所有对象共享同一份数据
    // 在编译阶段分配内存
    // 类内声明,类外初始化
    static int m_A;

    // 静态成员变量也是有访问权限的,加上public才可以类外访问
};

// 类内声明,类外初始化
int Person::m_A = 100;

void test01()
{
    Person p1;
    cout << p1.m_A << endl;  // 100

    Person p2;
    p2.m_A = 200;
    cout << p2.m_A << endl;  // 200

    // 所有对象共享同一份数据
    cout << p1.m_A << endl;  // 200
    
}

void test02()
{
    // 静态成员变量,不属于某个对象上,所有对象都共享同一份数据
    // 因此静态成员变量有两个访问方式

    // 1.通过对象进行访问
    Person p;
    cout << p.m_A << endl;

    // 2.通过类名进行访问
    cout << Person::m_A << endl;
    
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}