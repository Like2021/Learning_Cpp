#include<iostream>
using namespace std;
#include<string>

void test01()
{
    // 第一种方式
    pair<string, int>p("like", 20);
    cout << p.first << " " << p.second << endl;

    // 第二种方式
    pair<string, int>p2 = make_pair("Like", 20);
    cout << p2.first << " " << p2.second << endl;

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}