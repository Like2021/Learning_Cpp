#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

class MyPrint
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

	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

    cout << "替换前: " << endl;

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    cout << "替换后: " << endl;

    // 替换操作，将所有20替换成2000
    replace(v.begin(), v.end(), 20, 2000);
    
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}