#include<iostream>
using namespace std;

// 修饰形参,防止误操作
void showValue(const int &val)// val不在可以修改,即指针对应的值不可以修改
{
    cout << val << endl;
}

int main()
{
    int a = 10;
    const int & ref = 10;// 加上const之后 int temp = 10; const int & ref = temp;

    showValue(a);

    system("read -p 'Press Enter to continue...' var");
}