#include<iostream>
using namespace std;
#include<queue>
#include<string>

// 是一种先进先出的数据结构，有两个口
// 只有队头队尾能被外界访问，因此不允许有遍历行为

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
    // 创建队列
    queue<Person>q;

    // 准备数据
    Person p1("Like1", 20);
    Person p2("Like2", 240);
    Person p3("Like3", 90);
    Person p4("Like4", 200);

    // 入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << q.size() << endl;

    // 判断只要队列不为空，查看队头，查看队尾，出队
    while (!q.empty())
    {
        // 查看队头
        cout << "队头: " << q.front().m_Name << " " << q.front().m_Age << endl;
        // 查看队尾
        cout << "队尾: " << q.back().m_Name << " " << q.back().m_Age << endl;

        // 出队
        q.pop();
    }

    cout << q.size() << endl;
    
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}