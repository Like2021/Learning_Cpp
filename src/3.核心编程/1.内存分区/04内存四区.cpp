#include<iostream>
using namespace std;

int * func()
{
    //利用new关键字 可以将数据开辟到堆区
    //指针本质是局部变量 在栈区 但指针指向保存的数据发在堆区
    int * p = new int(10);
    return p;
}
int main()
{
    //在堆区开辟数据
    int *p = func();
    cout << *p << endl;

    system("pause");

    return 0;
}