#include<iostream>
using namespace std;
#include<string>

template<class T1, class T2>
class Person
{
    public:
    Person (T1 name, T2 age);
    // {
    //     this->m_Age = age;
    //     this->m_Name = name;
    // }

    void showPerson();
    // {
    //     cout << this->m_Name << " " << m_Age << endl;
    // }

    T1 m_Name;
    T2 m_Age;
};

// 构造函数的类外实现
template<class T1, class T2>
Person<T1, T2> :: Person(T1 name, T2 age)
{
    this->m_Age = age;
    this->m_Name = name;
}

// 成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2> :: showPerson()
{
    cout << this->m_Name << " " << m_Age << endl;
}

void test01()
{
    Person<string, int> p("Like", 20);
    p.showPerson();
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}