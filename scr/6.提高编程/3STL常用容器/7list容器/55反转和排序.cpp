#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

void printList(const list<int>&L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    // 降序 v1>v2
    return v1 > v2;
}

void test01()
{
    // 反转
    list<int>L1;

    L1.push_back(20);
    L1.push_back(40);
    L1.push_back(50);
    L1.push_back(30);
    L1.push_back(10);

    printList(L1);

    L1.reverse();
    cout << "反转后: " << endl;
    printList(L1);

    // 排序
    // sort(L1.begin(), L1.end());  // 所有不支持随机访问迭代器的容器，不可以使用标准算法

    // 这种容器，内部会提够对应算法
    L1.sort();
    cout << "排序后: " << endl;
    printList(L1);

    // 降序
    L1.sort(myCompare);
    cout << "排序后: " << endl;
    printList(L1);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}