#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void myPrint(int val)
{
    cout << val << endl;
}


void test01()
{
    vector<int> v;

    // 插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // // 通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin();  // 起始迭代器  指向容器中的第一个元素
    // vector<int>::iterator itEnd = v.end();  // 起始迭代器  指向容器中的最后一个元素的下一个位置

    // // 第一种遍历
    // while(itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // // 第二种遍历
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // 第三种 利用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);

}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}
