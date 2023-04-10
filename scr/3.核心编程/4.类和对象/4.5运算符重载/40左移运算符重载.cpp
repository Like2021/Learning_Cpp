#include<iostream>
using namespace std;

// 左移运算符重载
// 不会利用成员函数重载

class Person
{
    friend ostream & operator<<(ostream &cout, Person &p);
    
    private:
    int m_A;
    
    public:
    Person (int a, int b)
    {
        m_A = a;
        m_B = b;
    }
    int m_B;
};

// 只能利用全局函数重载
// 用友元就可以访问private
ostream & operator<<(ostream &cout, Person &p)  // 这里的cout和p都是别名，可以换的
{
    cout << "m_A = " << p.m_A << endl;;
    cout << "m_B = " << p.m_B;
    return cout;  // 用ostream &接受返回值cout，保证调用时可以链式输出
}

void test01()
{
    Person p(10, 10);  // 利用构造函数赋初值
    // p.m_A = 10;
    // p.m_B = 20;

    cout << p << endl;  // 但，用void重载是不能加endl;的
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}