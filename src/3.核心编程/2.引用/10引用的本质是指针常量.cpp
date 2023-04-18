#include<iostream>
using namespace std;

// 引用的本质是指针常量
// 即指针的指向不可更改,但指向的值可以更改

void func(int& ref)
{
    ref = 100;
}

int main()
{
    int a = 10;

    int& ref = a;// 自动转换为int* const ref = &a
    ref = 20;// 自动转换为*ref = 20

    cout << a << endl;
    func(a);
    cout << ref << endl;
}