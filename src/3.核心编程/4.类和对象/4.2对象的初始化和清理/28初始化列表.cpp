#include<iostream>
using namespace std;

// 初始化列表

class Person
{
public:
    int m_A;
    int m_B;
    int m_C;

    // 利用初始化列表初始化属性
    Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
    {

    }

};

void test01()
{
    Person p1(10, 20, 30);
    cout << p1.m_A << "\t" << p1.m_B << "\t" << p1.m_C << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}