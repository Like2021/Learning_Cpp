#include<iostream>
using namespace std;

#include<map>

void test01()
{
    map<int, int>m;

    // 无序插入也会自动排序成从小到大
    m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

class MyCompare
{
    public:
    bool operator()(int v1, int v2)
    {
        // 降序排列
        return v1 > v2;
    }
};

// 修改排序规则
void test02()
{
    map<int, int, MyCompare>m;

    m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");
}