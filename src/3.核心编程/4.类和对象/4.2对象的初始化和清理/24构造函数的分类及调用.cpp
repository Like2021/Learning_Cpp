#include<iostream>
using namespace std;

// 分类
// 有参和无参
// 普通和拷贝
class Person
{
public:
    // 无参构造函数
    Person()
    {
        cout << "调用无参构造函数" << endl; 
    };
    // 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "调用有参构造函数" << endl; 
    };
    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的属性拷贝
        age = p.age;
        cout << "调用拷贝构造函数" << endl; 
    };

    ~Person()
    {
        cout << "调用析构函数" << endl;
    };

    // 这个类有个属性age
    int age;
};

// 调用
void test01()
{
    // 1.括号法
    // Person p1;  // 调用默认构造函数的调用
    // Person p2(10);  // 调用有参
    // Person p3(p2);  // 调用拷贝
    
    // cout << "p2.age:" << p2.age << endl;
    // cout << "p3.age:" << p3.age << endl;

    // 注意事项
    // 调用默认构造函数的时候, 不要加括号()
    // 编译器会认为这是一个函数的声明, 类似与 void func();
    // Person p1();

    // 2.显示法
    // Person(10);  // 匿名对象 特点:当前行执行后,自动回收

    Person p1;
    Person p2 = Person(10);  // 有参构造
    Person p3 = Person(p2);  // 拷贝构造

    // 注意事项
    // 不要利用拷贝构造函数, 来初始化匿名对象
    // Person(p3);  // 这个等价于 Person p3

    // 3.隐式法
    Person p4 = 10;  // 相当于Person p4 = Person(10);
    Person p5 = p4;  // 调用拷贝构造

};

int main()
{
    // Person p;
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}