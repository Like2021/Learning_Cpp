#include<iostream>
using namespace std;
#include<set>

/*
* `find(key);`                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
* `count(key);`                //统计key的元素个数，并返回
*/

void test01()
{
    set<int>s1;

    // 插入
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);

    // 查找
    set<int>::iterator pos = s1.find(30);

    if (pos != s1.end())
    {
        cout << "找到元素，即: " << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

// 统计
void test02()
{
    set<int>s1;

    // 插入
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);

    int num = s1.count(30);  // 对于set而言，因为不允许插入重复数，所以不是0就是1
    cout << "num = " << num << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");
}