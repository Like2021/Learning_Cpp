#include<iostream>
using namespace std;

// 空指针调用成员函数
// 空指针无法调用成员变量

class Person
{
    public:

    void showClassName()
    {
        cout << "this is Person class" << endl;
    }

    void showPersonAge()
    {
        cout << "age = " << m_Age << endl;
    }

    int m_Age;
};

void test01()
{
    Person * p = NULL;

    p->showClassName();
    // p->showPersonAge();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}