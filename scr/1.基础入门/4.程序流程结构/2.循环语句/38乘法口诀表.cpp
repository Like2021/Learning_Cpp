#include<iostream>
using namespace std;



void test01()
{
    // i是行数
    for (int i = 1; i <= 9; i++)
    {
        // cout << i << endl;
        // j是列数
        for (int j = 1; j <= i; j++)  // 当前列数小于等于行数
        {
            cout << j << " * " << i << " = " << j*i << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}