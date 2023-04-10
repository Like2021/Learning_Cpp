#include<iostream>
using namespace std;
#include<string>

template<class T1, class T2>
class Person
{
    public:
    Person(T1 name, T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    void showPerson()
    {
        cout << m_Name << " " << m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

// 1.指定传入的类型
void printPerson1(Person<string, int>&p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int>p("LK", 100);
    printPerson1(p);
}

// 2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
    p.showPerson();
    cout << "T1的类型" << typeid(T1).name() << endl;
}

void test02()
{
    Person<string, int>p("LIKe", 100);
    printPerson2(p);
}

// 3.整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << typeid(T).name() << endl;
}

void test03()
{
    Person<string, int>p("Like", 10);
    printPerson3(p);
}

int main()
{
    // test01();
    // test02();
    test03();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}