#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>

class Greater3
{
    public:
    bool operator()(int val)
    {
        return val > 3;
    }
};

// 统计内置数据类型
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

    int num = count_if(v.begin(), v.end(), Greater3());
    cout << num << endl;
}

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

class AgeGreater25
{
    public:
    bool operator()(const Person &p)
    {
        return p.m_Age > 25;
    }
};

// 统计自定义数据类型
void test02()
{
    vector<Person>v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

    int num = count_if(v.begin(), v.end(), AgeGreater25());
    cout << num << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");
}