#include<iostream>
using namespace std;
#include<set>

/*
set和multiset区别:

set不允许容器中有重复的元素
multiset允许容器中有重复的元素

简介:
所有元素都会在插入时自动被排序
*/

void printSet(set<int>&s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int>s1;

    // 插入数据，只有insert方式
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);

    printSet(s1);

    // 拷贝构造
    set<int>s2(s1);
    printSet(s2);

    // 赋值操作
    set<int>s3;
    s3 = s2;
    printSet(s3);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}