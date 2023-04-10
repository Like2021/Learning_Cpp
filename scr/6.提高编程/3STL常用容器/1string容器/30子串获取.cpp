#include<iostream>
using namespace std;

#include<string>

void test01()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);  // 从索引1开始，截取3个字符

    cout << subStr << endl;
}

// 实用操作
void test02()
{
    string email = "Like@sina.com";

    // 从邮件地址中获取用户名信息
    int pos = email.find("@");  // 返回@的索引  4
    cout << pos << endl;
    string usrName = email.substr(0, pos);  // 截取4个
    cout << usrName << endl;

}

int main()
{
    // test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}