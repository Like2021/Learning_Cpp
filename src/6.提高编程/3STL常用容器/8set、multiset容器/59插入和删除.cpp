#include<iostream>
using namespace std;
#include<set>
/*
* `insert(elem);`           //在容器中插入元素。
* `clear();`                    //清除所有元素
* `erase(pos);`              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
* `erase(beg, end);`    //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
* `erase(elem);`            //删除容器中值为elem的元素。
*/

void printSet(const set<int>&s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int>s1;

    // 插入
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);

    printSet(s1);

    // 删除
    s1.erase(s1.begin());  // 和插入顺序无关，要看容器内的顺序，因为set会自动排序

    // 删除重载版本
    s1.erase(30);
    printSet(s1);

    // 清空
    // s1.erase(s1.begin(), s1.end());
    s1.clear();
    printSet(s1);

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}