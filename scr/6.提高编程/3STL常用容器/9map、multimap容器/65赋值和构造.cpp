#include<iostream>
using namespace std;
#include<map>
/*
简介:
* map中所有元素都是pair
* pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
* 所有元素都会根据元素的键值自动排序

本质:
map/multimap属于关联式容器，底层结构是用二叉树实现。

优点:
可以根据key值快速找到value值

map和multimap区别:
- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素
*/

void printMap(map<int, int>&m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << " value = " << it->second << endl; 
    }
    cout << endl;
}

void test01()
{
    // 创建map容器
    map<int, int>m;

    // 插入数据
    // 会自动按照key排序
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));

    printMap(m);

    // 拷贝构造
    map<int, int>m2(m);
    printMap(m2);

    // 赋值
    map<int, int>m3;
    m3 = m2;
    printMap(m3);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}