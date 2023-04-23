#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

// 反转算法，不需要容器为有序

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

    cout << "反转前: " << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    cout << "反转后: " << endl;
    reverse(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}