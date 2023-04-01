#include<iostream>
using namespace std;

// 第一种解决方式，直接包含源文件
// #include"person.cpp"

// 第二种方法，将.h和.cpp中的内容放到一起，将后缀改为.hpp
#include"person.hpp"

// template<class T1, class T2>
// class Person
// {
//     public:
//     Person(T1 name, T2 age);
//     // {
//     //     this->m_Age = age;
//     //     this->m_Name = name;
//     // }

//     void showPerson();
//     // {
//     //     cout << this->m_Name << " " << this->m_Age << endl;
//     // }

//     T1 m_Name;
//     T2 m_Age;
// };

// template<class T1, class T2>
// Person<T1, T2> :: Person(T1 name, T2 age)
// {
//     this->m_Age = age;
//     this->m_Name = name;
// }

// template<class T1, class T2>
// void Person<T1, T2> :: showPerson()
// {
//     cout << m_Name << " " << m_Age << endl;
// }

void test01()
{
    Person <string, int> p("Like", 20);
    p.showPerson();
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}