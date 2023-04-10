#include<iostream>
using namespace std;



void test01()
{
    // 在循环语句中，跳过本次循环中余下的循环语句，执行下一次循环
    for (int i = 0; i <= 100; i++)
    {
        // 奇数输出，偶数不输出
        if (i % 2 == 0)
        {
            continue;
        }
        cout << i << endl;
    }
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}