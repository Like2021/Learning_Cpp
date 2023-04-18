#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Person
{
    public:
    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person>v;

    Person p1("Like", 20);
    Person p2("Like", 30);
    Person p3("Like", 40);
    Person p4("Like", 50);
    Person p5("Like", 60);

    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << (*it).m_Name << " " << (*it).m_Age << endl;  // (*it)解出来是一个Person类型的数据
        cout << it->m_Name << " " << it->m_Age << endl;  // it可以当作是一个指针

    }
}

// 存放自定义数据类型 指针
void test02()
{
    vector<Person*>v;

    Person p1("Like", 20);
    Person p2("Like", 30);
    Person p3("Like", 40);
    Person p4("Like", 50);
    Person p5("Like", 60);

    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_Name << " " << (*it)->m_Age << endl;  // 这里就变成了 *it之后 仍旧是一个Person*指针
    }
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}