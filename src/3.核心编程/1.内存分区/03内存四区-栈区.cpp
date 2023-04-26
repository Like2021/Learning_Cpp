#include<iostream>
using namespace std;

/*
​由编译器自动分配释放, 存放函数的参数值,局部变量等
​注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器在函数执行后自动释放
*/

// int* func(int b)  // 形参数据也会放在栈区
// {
//     b = 100;
//     int a = 10;  // 局部变量

//     // 提示: 
//     // warning: address of local variable ‘a’ returned
//     return &a;  // 返回局部变量的地址
// }

void test01()
{
    // int* p = func(20);
    // cout << *p << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}