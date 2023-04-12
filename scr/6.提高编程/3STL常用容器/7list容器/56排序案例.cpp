#include<iostream>
using namespace std;
#include<list>
#include<string>


/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/

class Person
{
    public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name; // 姓名
    int m_Age;  // 年龄
    int m_Height;  // 身高
};

void printList(const list<Person>&L)
{
    for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "name: " << (*it).m_Name << " age: " << it->m_Age << " height: " << it->m_Height << endl;
    }
}

// 指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    // 按年龄做升序
    if (p1.m_Age == p2.m_Age)
    {
        // 年龄相同的情况下 ，按身高降序
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return p1.m_Age < p2.m_Age;
    }
}

void test01()
{
    // 创建容器
    list<Person>L;

    // 准备数据
	Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

    // 插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    printList(L);

    // 排序
    cout << "排序后: ---------------------------------" << endl;
    L.sort(comparePerson);
    printList(L);

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}