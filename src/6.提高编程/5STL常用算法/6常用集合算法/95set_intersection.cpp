#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<numeric>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int>vTarget;

    // 开辟空间
    // 特殊情况 大容器包含小容器，取两个容器大小的最小值
    vTarget.resize(min(v1.size(), v2.size()));

    // 获取交集
    // 返回一个交集位置的迭代器
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    // cout << *itEnd << endl;

    // for_each(vTarget.begin(), vTarget.end(), myPrint);
    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}