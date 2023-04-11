#include<iostream>
using namespace std;
#include<stack>

// 只有栈顶的数据可以操作，不允许有遍历的行为
// 特点: 符合先进后出的数据结构

// 栈可以判断容器是否为空  empty()
// 栈可以返回元素个数  size()



void test01()
{
    stack<int>s;

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "栈的大小: " << s.size() << endl;

    // 只要栈不为空，就查看栈顶，并且执行出栈操作
    while (!s.empty())
    {
        // 查看栈顶元素
        cout << "栈顶元素: " << s.top() << endl;

        // 出栈
        s.pop();
    }
    cout << "栈的大小: " << s.size() << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}