#include<iostream>
using namespace std;
#include<list>

void printList(const list<int>&L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int>L1;

    // 插入数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    // 判断容器是否为空
    if (L1.empty())
    {
        cout << "容器为空" << endl;
    }
    else
    {
        cout << "容器不为空" << endl;
        cout << "元素个数: " << L1.size() << endl;
    }

    // 重新指定大小
    // 默认填充为0,也可以指定
    // L1.resize(10);
    L1.resize(10, 1000);
    printList(L1);

    L1.resize(2);
    printList(L1);

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}