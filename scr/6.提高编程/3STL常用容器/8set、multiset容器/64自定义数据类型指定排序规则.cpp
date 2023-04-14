#include<iostream>
using namespace std;
#include<set>

class Person
{
    public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

// 仿函数
class comparePerson
{
    public:
    bool operator()(const Person&p1, const Person&p2)
    {
        // 按照年龄 降序
        return p1.m_Age > p2.m_Age;

    }
};

void test01()
{
    set<Person, comparePerson>s;

    // 创建Person对象
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "name: " << it->m_Name << " age: " << it->m_Age << endl;
    }
    cout << endl;



}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}