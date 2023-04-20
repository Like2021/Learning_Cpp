#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// 普通函数
void print01(int val)
{
    cout << val << " ";
}

// 仿函数
class print02
{
    public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int>v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 普通函数只需要传入函数名
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    // 仿函数需要传入函数对象
    for_each(v.begin(), v.end(), print02());
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}