#include<iostream>
using namespace std;



void test01()
{
    // 和while的区别: 先执行循环语句，再判断循环条件
    // 打印0~9
    int num = 0;

    // do{循环语句} while(循环条件;);
    do
    {
        cout << num << endl;
        num ++;
    } 
    while (num < 10);
    
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}