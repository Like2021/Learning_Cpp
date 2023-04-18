#include<iostream>
using namespace std;
#include<string>
// 模板局限性

// 自定义一个数据类型
class Person
{
    public:

    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    string m_Name;
    int m_Age;
};

// 对比两个数据是否相等
template<class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 具体话Person版本的代码实现，具体化优先调用
template<> bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void test01()
{
    int a = 10;
    int b = 20;

    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
}

void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 110);

    // 1.可以重载=运算符
    // 2.提供Person类型的重载
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

int main()
{
    test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}