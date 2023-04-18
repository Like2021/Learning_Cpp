#include<iostream>
using namespace std;
#include<string>

void test01()
{
    string s1 = "我";
    s1 += "爱玩游戏";
    cout << s1 << endl;

    s1 += ':';
    cout << s1 << endl;

    string s2 = " LOL DNF";
    s1 += s2;
    cout << s1 << endl;

    string s3 = "I";
    s3.append(" love");
    cout << s3 << endl;

    s3.append(" game abc", 5);
    cout << s3 << endl;

    // s3.append(s2);
    // cout << s3 << endl;

    s3.append(s2, 4, 4);  // 从s2的索引4开始截取，一共截取4个
    cout << s3 << endl;

}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}