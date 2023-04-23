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

    // 创建差集的目标容器
    vector<int>vTarget;

    // 开辟空间
    // 特殊情况 没有交集 取容器空间最大的值
    vTarget.resize(max(v1.size(), v2.size()));

    // vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    vector<int>::iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());


    // for_each(vTarget.begin(), vTarget.end(), myPrint);
    for_each(vTarget.begin(), itEnd, myPrint);

    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}