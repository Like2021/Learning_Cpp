#include<iostream>
using namespace std;
#include<string>

class Person
{
public:
    Person(string name, int age)
    {
        m_Age = age;
        m_Name = name;
    }

    // 重载 ==
    bool operator==(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }

        return false;
    }

    // 重载 ！=
    bool operator!=(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }

        return true;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("Like", 18);
    Person p2("Like1", 18);

    if(p1 != p2)
    {
        cout << "p1与p2不相等" << endl;
    }
    else
    {
        cout << "p1和p2相等" << endl;
    }
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}