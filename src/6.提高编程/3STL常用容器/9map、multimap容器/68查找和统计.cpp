#include<iostream>
using namespace std;

#include<map>

void test01()
{
    // 查找
    map<int, int>m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int>::iterator pos = m.find(3);  // 找不到会返回end()

    if (pos != m.end())
    {
        cout << "查找到key = " << pos->first << " value = " << (*pos).second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    // 统计
    int num = m.count(3);  // 结果非0即1,map容器中不允许插入重复的key，mutimap则可以
    cout << "num = " << num << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}