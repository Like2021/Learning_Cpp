#include<iostream>
using namespace std;



void test01()
{
    // 只要循环条件的结果为真，就执行循环语句，反之退出循环
    // 打印0~9
    int num = 0;

    // while(循环条件){循环语句;};
    // 写循环条件要避免死循环的出现
    while (num < 10)
    {
        cout << num << endl;
        num++;
    }
    
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}