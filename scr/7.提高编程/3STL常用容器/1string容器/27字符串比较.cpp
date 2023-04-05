#include<iostream>
using namespace std;
#include<string>

void test01()
{
    string str1 = "xello";
    string str2 = "hello";

    if (str1.compare(str2) == 0)  // 逐一对比字符的ASCII
    {
        cout << "str1 == str2" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 > str2" << endl;
    }
    else
    {
        cout << "str1 < str2" << endl;
    }
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}