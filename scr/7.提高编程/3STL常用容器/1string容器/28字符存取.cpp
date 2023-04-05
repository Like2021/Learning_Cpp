#include<iostream>
using namespace std;



void test01()
{
    string str = "hello";
    cout << str << endl;

    // 1.通过[]访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 2.通过at的方法
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 修改单个字符
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}