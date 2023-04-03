#include<iostream>
using namespace std;
#include<string>


void test01()
{
    string s1;  // 默认构造

    const char * str = "hello world";
    string s2(str);  // 使用字符串str初始化
    cout << s2 << endl;

    string s3(s2);  // string(const string & str)  使用一个string对象初始化另一个string  拷贝构造
    cout << s3 << endl;

    string s4(10, 'a');
    cout << s4 << endl;
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}