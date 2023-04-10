#include<iostream>
using namespace std;



void test01()
{
    // 满足循环条件，执行循环语句
    // for (起始表达式; 条件表达式; 末尾循环体){循环语句;}

    // 打印0~9
    // int i = 0;  // 起始表达式
    for (int i = 0; i < 10; i++)  // 可以将()中的内容拆开写，但要保留;
    {
        // if (i > 10)  // 条件表达式
        // {
        //     break;
        // }
        cout << i << endl;
        // i++;  // 末尾循环体可以写到循环语句中
    }
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}