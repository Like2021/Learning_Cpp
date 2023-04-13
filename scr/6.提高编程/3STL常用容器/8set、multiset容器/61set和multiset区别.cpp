#include<iostream>
using namespace std;
#include<set>
/*
* set不可以插入重复数据，而multiset可以
* set插入数据的同时会返回插入结果，表示插入是否成功
* multiset不会检测数据，因此可以插入重复数据
*/

void boolInsert(pair<set<int>::iterator, bool>&ret)
{
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
}

void test01()
{
    set<int>s;

    pair<set<int>::iterator, bool>  ret = s.insert(10);

    boolInsert(ret);

    ret = s.insert(10);

    boolInsert(ret);

    // multset
    multiset<int>ms;

    // 允许插入重复的值
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}