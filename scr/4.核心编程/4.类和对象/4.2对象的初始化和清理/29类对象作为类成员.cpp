#include<iostream>
using namespace std;
#include<string>

// 类的成员可以是另一个类的对象,称为对象成员

// 当其他类对象作为本类的成员
// 构造的时候,先构造其他类对象,再构造本身的

// 析构函数则相反

class Phone
{
public:

    Phone(string pName):m_PName(pName)
    {
        cout << "Phone构造函数调用" << endl;
    }

    // 手机品牌名
    string m_PName;
};

class Person
{
public:

    Person(string name, string pName):m_Name(name), m_Phone(pName)
    {
        // 相当于
        // Phone m_Phone = pName;
        cout << "Person构造函数调用" << endl;
    }

    // 姓名
    string m_Name;

    // 手机
    Phone m_Phone;
};

void test01()
{
    Person p("Like", "iphone11");

    // 注意这里不能是
    // cout << p.m_Phone << endl;

    // Phone m_Phone
    // 这是一个类,不是一个值
    cout << p.m_Name << "\t" << p.m_Phone.m_PName << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}