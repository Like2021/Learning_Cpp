#include<iostream>
using namespace std;

// 1.创建一个类,C++编译器会自动添加三个函数
// 默认构造
// 析构函数
// 拷贝构造:将所有值进行拷贝


// 2.如果我们写了有参构造,编译器就不会添加默认构造,如果调用默认构造就需要自己写,否则报错
// 3.如果写了拷贝构造,编译器就不会自动添加其他的构造函数了,再想调用其他的构造函数就需要自己写
class Person
{
public:
    int m_Age;
    Person()
    {
        cout << "调用无参构造函数" << endl; 
    }

    Person (int age)
    {
        m_Age = age;
        cout << "调用有参构造函数" << endl; 
    }

    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的属性拷贝
        m_Age = p.m_Age;
        cout << "调用拷贝构造函数" << endl; 
    }

    ~Person()
    {
        cout << "调用析构函数" << endl;
    };
};

void test01()
{
    Person p;
    p.m_Age = 18;

    Person p2(p);
    cout << p2.m_Age << endl;
}

int main()
{
    // Person p1;
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}