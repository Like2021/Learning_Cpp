#include<iostream>
using namespace std;

// 面试经典问题

// 总结:如果属性有在堆区开辟的,一定要自己提供拷贝构造函数,防止浅拷贝带来的问题

// 浅拷贝
// 简单的赋值拷贝操作

// 深拷贝
// 在堆区重新申请空间,进行拷贝操作

class Person
{
public:
    int m_Age;
    int *m_Height;
    Person()
    {
        cout << "调用无参构造函数" << endl; 
    }

    Person (int age, int height)
    {
        m_Age = age;

        m_Height = new int(height);

        cout << "调用有参构造函数" << endl; 
    }

    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的属性拷贝
        m_Age = p.m_Age;

        // 不能写
        // m_Height = p.m_Height;

        // 深拷贝操作
        // 重新在堆区开辟一个内存,保留它的地址,防止析构函数多次释放相同地址的内存
        m_Height = new int(*p.m_Height);

        cout << "调用拷贝构造函数" << endl; 
    }

    ~Person()
    {
        // 析构函数,将堆区开辟的数据做释放操作
        // 堆区数据,手动开辟,手动释放
        // 浅拷贝带来的问题,就是堆区的内存重复释放
        // 所以需要深拷贝,即自己实现拷贝函数
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }

        cout << "调用析构函数" << endl;
    }
};

void test01()
{
    Person p1(18, 180);

    cout << "p1.age" << p1.m_Age << "\t" << "p1.height" << *p1.m_Height << endl;

    Person p2(p1);  // 有浅拷贝,所以p2的age也是18

    cout << "p2.age" << p2.m_Age << "\t" << "p2.height" << *p2.m_Height << endl;

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}