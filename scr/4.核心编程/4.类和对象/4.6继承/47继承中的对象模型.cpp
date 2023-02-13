#include<iostream>
using namespace std;

// 基类
class Base
{
    public:
    int m_A;

    protected:
    int m_B;

    private:
    int m_C;  // 父类中所有的非静态成员属性都会被继承，包括私有成员，但是无法访问
};

// 派生类
class Son : public Base
{
    public:
    int m_D;
};

void test01()
{
    cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}