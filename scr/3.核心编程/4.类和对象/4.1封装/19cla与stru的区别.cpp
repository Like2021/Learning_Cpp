#include<iostream>
using namespace std;

class C1
{
    int m_A;
};

struct C2
{
    int m_A;
};


int main()
{
    // struct 默认权限是公共public
    // class 默认权限是私有private

    C1 c1;
    // 私有权限类外不能访问
    // c1.m_A = 100;  

    C2 c2;
    c2.m_A = 100;

    cout << c2.m_A << endl;

    system("pause");

    return 0;
}