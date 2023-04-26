#include<iostream>
using namespace std;

/*
​由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
​在C++中主要利用new在堆区开辟内存
*/

int * func()
{
    // 利用new关键字 可以将数据开辟到堆区
    // 指针 本质是局部变量，放在栈区，但指针指向其所保存的数据放在堆区

    int * p = new int(10);  // 初始化保存的数据为10，并返回其地址
    return p;
}
int main()
{
    // 在堆区开辟数据
    int *p = func();
    cout << *p << endl;

    system("read -p 'Press Enter to continue...' var");

    return 0;
}