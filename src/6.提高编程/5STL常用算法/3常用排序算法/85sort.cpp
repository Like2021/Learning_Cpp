#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<functional>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 降序操作
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}