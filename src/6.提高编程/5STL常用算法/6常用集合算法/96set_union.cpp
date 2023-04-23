#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<numeric>

// 必须是有序的容器

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
    // 特殊情况 两个容器没有交集，并集就是容器size相加
    vTarget.resize(v1.size() + v2.size());

    // 返回交集结束的位置
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}