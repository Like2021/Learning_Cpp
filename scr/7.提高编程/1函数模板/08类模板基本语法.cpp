#include<iostream>
using namespace std;
#include<string>

// 类模板
template <class NameType, class AgeType>  // 两个不同的通用类型
class Person
{
    public:
    Person(NameType name, AgeType age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void showPerson()
    {
        cout << this->m_Age << " " << this->m_Name << endl;
    }

    NameType m_Name;
    AgeType m_Age;

};

void test01()
{
    // 类型参数化
    Person<string, int>p1("Like", 10);
    p1.showPerson();
    
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}