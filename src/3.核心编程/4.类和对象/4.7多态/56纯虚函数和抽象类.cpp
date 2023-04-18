#include<iostream>
using namespace std;

// 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 纯虚函数语法：virtual 返回值类型 函数名 （参数列表） = 0；
// 只要类中有一个纯虚函数，这个类也称为抽象类

// 特点：
// 无法实例化对象
// 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

// 父类
class Base
{
    public:

    virtual void func() = 0;
};

// 子类
class Son : public Base
{
    public:

    void func()
    {
        cout << "重写纯虚函数" << endl;
    }
};

void test01()
{
    // Son s;
    // s.func();

    // 父类的指针接受子类对象
    Base * base = new Son;
    base->func();
    delete base;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}