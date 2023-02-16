#include<iostream>
using namespace std;
#include<string>

// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 解决方法：将父类中的析构函数改为虚析构或者纯虚析构

// 两者的共性
// 都需要具体的函数实现

// 区别
// 纯虚析构的类，无法实例化对象

class Animal
{
    public:

    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }

    // 纯虚函数
    virtual void speak() = 0;

    // 虚析构
    // virtual ~Animal()
    // {
    //     cout << "Animal析构函数调用" << endl;
    // }

    // 纯虚析构
    // 父类可能也有属性开辟到堆区，所以需要函数实现
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animal纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
    public:

    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }

    virtual void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }

    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    string *m_Name;
};

void test01()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时，不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄漏情况
    // 解决方法：虚析构
    delete animal;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}