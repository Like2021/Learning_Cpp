#include<iostream>
using namespace std;
#include<string>

// 通过全局函数 打印Person信息

template<class T1, class T2>
class Person;

// 类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p)
{
    cout << p.m_Name << " " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
    // 全局函数 类内实现
    friend void printPerson(Person<T1, T2> p)
    {
        cout << p.m_Name << " " << p.m_Age << endl;
    }

    // 全局函数 类外实现
    // 加空模板参数列表<>
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在,即把类外实现放在最前面
    friend void printPerson2<>(Person<T1, T2> p);

    public:
    Person(T1 name, T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }


    private:
    T1 m_Name;
    T2 m_Age;
};


void test01()
{
    Person <string,int> p("Like", 20);
    printPerson2(p);
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}