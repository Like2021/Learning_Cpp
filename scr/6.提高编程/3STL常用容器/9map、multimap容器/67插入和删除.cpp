#include<iostream>
using namespace std;

#include<map>

void printMap(map<int, int>&m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int>m;

    // 插入
    m.insert(pair<int, int>(1, 10));

    m.insert(make_pair(2, 20));

    m.insert(map<int, int>::value_type(3, 30));

    m[4] = 40;

    // 不建议用[]插入，但可以用确定的key来访问value
    // cout << m[5] << endl;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    // 清空
    // m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}