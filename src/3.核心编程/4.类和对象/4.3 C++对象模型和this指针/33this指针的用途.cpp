#include<iostream>
using namespace std;

// 每个非静态成员函数都只有一份函数实例,也就是说多个同类型的对象会共用一个代码
// 那么:这块代码是如何区分哪个对象调用自己的呢

// C++提供this指针解决这个问题
// this指针指向调用成员函数的所属对象

// this指针是隐含每个非静态成员函数内的一种指针
// this指针不需要定义,直接使用即可

// 用途
// 当形参和成员变量同名时,可用this指针来区分
// 在类的非静态成员函数中返回对象本身,可使用return *this

class Person
{
    public:

    Person(int age)
    {
        // 不能写:
        // int age;
        // age = age;

        // 利用this解决名称冲突
        // 可以写:
        // int age;
        this->age = age;
    }

    // 返回对象本身用*this
    // 用Person&引用的方式才可以返回p2本身
    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;

        // this是指向p2的指针,而*this指向的就是p2这个对象本体
        return *this;
    }

    int age;

};

void test01()
{
    Person p1(18);

    cout << p1.age << endl;
}

void test02()
{
    Person p1(10);

    Person p2(10);

    p2.PersonAddAge(p1).PersonAddAge(p1);  // 链式编程思想

    cout << p2.age << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}