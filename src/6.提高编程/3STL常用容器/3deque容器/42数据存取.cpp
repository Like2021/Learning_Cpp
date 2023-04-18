#include<iostream>
using namespace std;
#include<deque>

void test01()
{
    deque<int>d1;
    for (int i = 1; i < 4; ++i)
    {
        d1.push_back(10*i);
        d1.push_back(100*i);
    }

    // 通过[]方式访问
    for (int i = 0; i < d1.size(); ++i)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    // 通过at方式访问
    for (int i = 0; i < d1.size(); ++i)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;

    // 访问头尾
    cout << d1.front() << endl;
    cout << d1.back() << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}