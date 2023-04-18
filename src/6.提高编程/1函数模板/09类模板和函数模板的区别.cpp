#include<iostream>
using namespace std;
#include<string>


template<class NameType, class AgeType = int>
class Person
{
    public:
    NameType m_Name;
    AgeType m_Age;

    Person(NameType name, AgeType age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    void showPerson()
    {
        cout << m_Age << " " << m_Name << endl;
    }
};

// 类模板没有自动类型推导的使用方式
void test01()
{
    // Person p("Like", 10);  // 错误
    Person<string, int>p("Like", 10);
    p.showPerson();
}

// 类模板在模板参数列表中有默认参数
void test02()
{
    Person<string>p("Like", 100);
    p.showPerson();
}

int main()
{
    // test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}