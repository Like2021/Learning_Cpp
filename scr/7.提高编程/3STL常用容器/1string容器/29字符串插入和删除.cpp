#include<iostream>
using namespace std;

#include<string>

void test01()
{
    string str = "hello";

    // 插入
    str.insert(1, "111");
    cout << str << endl;  // h111ello

    // 删除
    str.erase(1, 3);  // 从索引1开始，删除三个字符
    cout << str << endl;
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}