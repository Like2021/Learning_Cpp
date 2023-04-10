#include<iostream>
using namespace std;

// 成员变量和成员函数是分开存储的

class Person
{
    int m_A;  // 非静态成员变量,属于类的对象p上

    static int m_B;  // 静态成员,不属于类的对象p上

    void func()  // 成员函数,都不属于类的对象p上
    {

    }
};

int Person::m_B = 100;

void test01()
{
    Person p;

    // 空对象占用内存空间为1个字节
    cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
    Person p;

    // 空对象占用内存空间为4个字节
    cout << "size of p = " << sizeof(p) << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}