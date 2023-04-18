#include<iostream>
using namespace std;
#include<string>

// 查找
void test01()
{
    string str1 = "abcdefg";
    int pos = str1.find("de");  // 返回d的索引，如果查不到，返回-1
    cout << pos << endl;

    // rfind
    pos = str1.rfind("de");  // 从右往左查找，返回d的索引
    cout << pos << endl;
}

// 替换
void test02()
{
    string str1 = "abcdefg";

    str1.replace(1, 3, "1111");  // 从索引1的地方开始，替换3个字符，替换成"1111"

    cout << str1 << endl;
}

int main()
{
    // test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}