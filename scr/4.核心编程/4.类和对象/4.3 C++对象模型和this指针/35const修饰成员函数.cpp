#include<iostream>
using namespace std;

// 常函数
// 成员函数后加const,称为常函数
// 常函数内不可以修改成员属性
// 成员属性声明时,加关键字mutable后,在常函数中依然可以修改

class Person
{
    public:

    // 在成员函数后面加const,本质上修饰的是this指针,让指针指向的值也不可以修改
    // const Person * const this;
    void showPerson() const
    {
        // this->m_B = 100;
        
        // this指针的本质, 是指针常量, 指针的指向是不可以修改的
        // 指向的是实例化的对象
        // m_A = 100;  // 本质是this->m_A = 100;
        cout << "调用常函数" << endl;
    }

    int m_A = 100;
    mutable int m_B = 200;  // 这样就可以在常函数中就可以修改了
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
// 声明对象前加const称为常对象
// 只能调用常函数

void test02()
{
    const Person p;  // const一个对象,属性需要有初始化,

    p.m_B = 100;  // m_B是特殊值,在常对象下也可以修改

    p.showPerson();
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}