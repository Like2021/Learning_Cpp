#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int>&d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 两端操作
void test01()
{
    deque<int>d1;
    for (int i = 0; i < 5; ++i)
    {
        // 尾插
        d1.push_back(10*i);
        // 头插
        d1.push_front(20*i);
    }

    printDeque(d1);

    // 尾删
    d1.pop_back();
    // 头删
    d1.pop_front();
    printDeque(d1);
}

// 指定操作
void test02()
{
    deque<int>d1;

    for (int i = 0; i < 5; ++i)
    {
        // 尾插
        d1.push_back(10*i);
        // 头插
        d1.push_front(20*i);
    }

    // printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 100);
    // printDeque(d1);

    // 重载版本  插入2个1000
    d1.insert(d1.begin(), 2, 1000);
    printDeque(d1);

    // 按区间进行插入
    deque<int>d2;
    for (int i = 1; i < 4; ++i)
    {
        d2.push_back(i);
    }
    printDeque(d2);

    // 在d1的d1.begin()位置  插入d2.begin()~d2.end()的数据
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test03()
{
    deque<int>d1;
    for (int i = 1; i < 6; ++i)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 删除
    deque<int>::iterator it = d1.begin();
    // it++之后 做删除操作之后，it会继续指向d1.begin()
    it++;
    cout << *it << endl;
    // d1.erase(it);
    // printDeque(d1);

    // 按照区间的方式
    it++;
    cout << *it << endl;
    // d1.erase(it, d1.end());
    // printDeque(d1);

    // 清空函数
    d1.clear();
    printDeque(d1);
}

int main()
{
    // test01();
    // test02();
    test03();

    system("read -p 'Press Enter to continue...' var");

}