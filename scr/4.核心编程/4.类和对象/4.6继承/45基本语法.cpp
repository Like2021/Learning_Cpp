#include<iostream>
using namespace std;

// 继承
// class 子类 : 继承方式 父类

// 基类
class BasePage
{
    public:
    void base()
    {
        cout << "基类" << endl;
    }
};

// Java类
// 继承基类
class Java : public BasePage
{
    public:
    void content()
    {
        cout << "java类" << endl;
    }
};

void test01()
{
    Java ja;
    ja.base();
    ja.content();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}