#include<iostream>
using namespace std;
#include<unistd.h>

class Person
{
public: // 保证在外部可以调用
    //1.构造函数 进行初始化操作
    //没有返回值, 不用写void
    //可以有参数,可以发生重载
    //在创建对象的时候会自动调用一次
    Person()
    {
        cout << "调用构造函数" << endl; 
    };

    //2.析构函数,进行清理的操作
    //不可以有参数
    //对象销毁前,会自动调用一次
    ~Person()
    {
        cout << "调用析构函数" << endl;
    };
};

//不写自己的内容,编译器也会创建一个空的构造和析构函数
void test01()
{
    Person p; //创建一个对象, 在栈上的数据, test01执行完毕后, 释放内存

};

int main()
{
    // test01();

    Person p;

    // system("pause");
    system("read -p 'Press Enter to continue...' var");

    return 0;

}