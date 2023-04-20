#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>

void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);  // 必须是有序序列
    }

    // 如果是无序的，结构未知
    // v.push_back(2);

    // 查找是否有9
    bool ret = binary_search(v.begin(), v.end(), 9);

    if (ret)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}