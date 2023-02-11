#include<iostream>
using namespace std;
#include<string>

// 可以自己控制读写权限
// 对于写可以检测数据的有效性

class Person
{

    private:
    string m_Name;
    int m_Age;
    string m_Lover;


    public:
    // 设置姓名
    void setName(string name)
    {
        m_Name = name;
    }

    // 获取姓名
    string getName()
    {
        return m_Name;
    }

    // 获取年龄  可读可写 如果想修改(范围在0~100)
    int getAge()
    {
        // m_Age = 0;  // 初始化为0
        return m_Age;
    }

    // 设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 100)
        {
            m_Age = 0;
            cout << "Error" << endl;
            return;
        }

        m_Age = age;
    }

    // 设置情人
    void setLover(string lover)
    {
        m_Lover = lover;
    }
};

int main()
{
    Person p;
    p.setName("like");
    cout << p.getName() << endl;

    p.setAge(120);
    cout << p.getAge() << endl;

    p.setLover("cj");
    // cout << p.m_Lover << endl;  // 不可访问

    system("pause");

    return 0;

}