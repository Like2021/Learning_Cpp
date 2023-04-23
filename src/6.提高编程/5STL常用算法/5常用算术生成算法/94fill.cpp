#include<iostream>
using namespace std;

#include<vector>
#include<numeric>
#include<algorithm>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v;

    // 开辟空间  填充10个0
    v.resize(10);

    // 重新填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}