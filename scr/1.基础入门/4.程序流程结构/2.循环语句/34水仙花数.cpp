#include<iostream>
using namespace std;



void test01()
{

    // 水仙花数是指一个3位数，它的每个位上的数字的3次幂之和等于它本身
    // 1.将所有的三位数进行输出100~999
    int num = 100;
    do
    {
        // 2.在所有三位数中找到水仙花数
        int a = 0;  // 个位
        int b = 0;  // 十位
        int c = 0;  // 百位

        // 获取个位 取模于10
        a = num % 10;
        // 获取十位 整除于10 得到两位数 再取模于10
        b = num / 10 % 10;
        // 获取百位 直接整除于100
        c = num / 100;
        
        // 判断 个位^3 + 十位^3 + 百位^3 = 数字本身
        if (a*a*a + b*b*b + c*c*c == num)  // 如果是水仙花数才打印
        cout << num << endl;
        num++;
    }
    while (num < 1000);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}