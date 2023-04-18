#include<iostream>
using namespace std;

// 静态多态：函数重载和运算符重载属于静态多态，复用函数名
// 动态多态：派生类和虚函数实现运行时多态

// 静态多态的函数地址早绑定-编译阶段确定函数地址
// 动态多态的函数地址晚绑定-运行阶段确定函数地址


// 动态多态的条件
// 1.有继承关系
// 2.子类重写父类的虚函数

// 重载是函数名相同，参数不同
// 重写是返回值类型、函数名、参数列表完全相同

// 动物类
class Animal
{
    public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

// 猫类
class Cat : public Animal
{
    public:
    void speak()
    {
        cout << "喵叫" << endl;
    }
};

// 狗类
class Dog : public Animal
{
    public:
    void speak()
    {
        cout << "狗叫" << endl;
    }
};

// 执行说话的函数
// 地址早绑定，在编译阶段确定函数地址
// 如果想执行子类的同名函数，那么这个函数地址就不能提前绑定，需要在运行阶段绑定

// 动态多态使用
// 父类的指针或者引用 执行子类对象
// Animal &animal =cat

void doSpeak(Animal &animal)  // Animal &animal =cat
{
    animal.speak();
}

void test01()
{
    Cat cat;
    // Animal &animal =cat
    // 父类的引用 接受 子类的对象
    // 不使用动态多态会导致调用父类
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}