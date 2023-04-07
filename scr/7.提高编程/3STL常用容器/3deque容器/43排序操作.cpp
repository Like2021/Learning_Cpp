#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printDeque(const deque<int>&d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int>d;
    for (int i = 1; i < 4; ++i)
    {
        d.push_back(10*i);
        d.push_front(100*i);
    }

    printDeque(d);

    // 排序 默认排序规则是升序
    // 对于支持随机访问的迭代器的容器，都可以利用sort进行排序，如vector
    sort(d.begin(), d.end());
    printDeque(d);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}