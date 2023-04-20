#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<string>


// 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

// 查找内置数据类型
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找 容器中的5
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到: " << *it << endl;
    }
}

class Person
{
    public:

    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    // 重载 ==  让底层的find知道如何对比person数据类型
    bool operator==(const Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    string m_Name;
    int m_Age;
};

// 查找自定义数据类型
void test02()
{
    vector<Person>v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

    // 放入容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

    Person pp("bbb", 20);

    // 查找
    vector<Person>::iterator it = find(v.begin(), v.end(), pp);
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到: " << it->m_Name << " " << it->m_Age << endl;
    }
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");
}