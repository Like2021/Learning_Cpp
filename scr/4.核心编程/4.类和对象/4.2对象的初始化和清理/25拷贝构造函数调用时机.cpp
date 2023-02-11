#include<iostream>
using namespace std;

class Person
{
public:
    int m_Age;
    Person()
    {
        cout << "调用无参构造函数" << endl; 
    };

    Person (int age)
    {
        m_Age = age;
        cout << "调用有参构造函数" << endl; 
    };

    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的属性拷贝
        m_Age = p.m_Age;
        cout << "调用拷贝构造函数" << endl; 
    };

    ~Person()
    {
        cout << "调用析构函数" << endl;
    };
};

// 拷贝构造函数调用时机

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(10);
    Person p2(p1);

    cout << p2.m_Age << endl;
}
// 2.值传递的方式给函数参数传值
void doWork(Person p)
{

}

void test02()
{
    Person p;
    doWork(p);  // 这种情况也会调用拷贝构造函数
}
// 3.值方式返回局部对象
Person doWork2()
{
    Person p3;  // 调用的时候先析构这个,再析构test03中的p
    return p3;  // 返回的时候会创建一个新的Person
}

void test03()
{
    Person p = doWork2();  // 返回一个新的Person对象
}


int main()
{
    // test01();
    // test02();
    test03();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}