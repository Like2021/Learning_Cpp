#include<iostream>
using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
    int a = 10;
    int b = 20;

    mySwap(a, b);  // a与b数据类型一致，正确！
    cout << "a = " << a << endl;
}

// 2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
    cout << "func ing" << endl;
}

void test02()
{
    func<int>();  // 没指定T的数据类型
}


int main()
{
    test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}