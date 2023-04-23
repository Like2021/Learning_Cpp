#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int>v2;

    // 提前开辟空间
    // v2.resize(v1.size());

    // copy(v1.begin(), v1.end(), v2.begin());

    // 拷贝算法就相当与这样赋值
    v2 = v1;

    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}