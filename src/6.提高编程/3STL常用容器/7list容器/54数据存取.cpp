#include<iostream>
using namespace std;
#include<list>

// list 不支持随机访问

void test01()
{
    list<int>L1;

    // 插入数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    cout << "第一个元素: " << L1.front() << endl;
    cout << "最后一个元素: " << L1.back() << endl;

    // 迭代器不支持随机访问
    list<int>::iterator it = L1.begin();

    it++;  // 这样可以
    it--;  // 这样可以
    // it = it + 1;  // 这样不行，没有匹配的+运算符
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}