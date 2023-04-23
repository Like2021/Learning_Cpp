#include<iostream>
using namespace std;

#include<vector>
#include<numeric>

void test01()
{
    vector<int>v;

    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }

    // 在1000的基础上累加容器中的所有值
    int total = accumulate(v.begin(), v.end(), 1000);
    cout << total << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}