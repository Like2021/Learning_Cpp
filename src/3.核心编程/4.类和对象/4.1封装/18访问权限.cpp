#include<iostream>
using namespace std;

// 三种访问权限
// public 成员 类内可以访问 类外可以访问


// protected 成员 类内可以访问 类外不可以访问
// 继承中 子类可以访问父类的保护内容


// private 成员 类内可以访问 类外不可以访问
// 继承中 子类也不可以访问父类的保护内容

class Person
{
    public:
    string m_Name;

    protected:
    string m_Car;

    private:
    int m_Password;

    public:
    void func()
    {
        // 类内都可以访问
        m_Name = "Like";
        m_Car = "拖拉机";
        m_Password = 12312312;
    }
};

int main()
{
    Person p1;

    // 访问属性
    p1.m_Name = "李可";
}