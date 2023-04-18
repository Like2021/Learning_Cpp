#include<iostream>
using namespace std;
#include<string>

// 打印输出类
class MyPrint
{
public:

    // 重载()
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void test01()
{
    MyPrint myPrint;

    myPrint("hello world");  // 由于类似函数调用，被成为仿函数
}

// 仿函数没有固定写法，可以有返回值，也可以没有
// 加法类
class MyAdd
{
    public:

    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};

void test02()
{
    MyAdd myAdd;
    int ret = myAdd(100, 200);
    cout << "ret = " << ret << endl;

    // 匿名函数对象  类名+()
    cout << MyAdd()(100, 100) << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}