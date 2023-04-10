#include<iostream>
using namespace std;



void test01()
{
    // 可以无条件跳转语句
    // goto 标记;
    // 如果标记的名称存在，执行goto语句时，会跳转到标记的位置，然后往下执行

    cout << "1.xxxx" << endl;
    cout << "2.xxxx" << endl;
    goto FLAG;
    cout << "3.xxxx" << endl;
    cout << "4.xxxx" << endl;
    FLAG:
    cout << "5.xxxx" << endl;

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}