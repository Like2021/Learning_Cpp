#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    // 尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);

    // 尾删
    v1.pop_back();
    printVector(v1);

    // 插入
    v1.insert(v1.begin(), 100);  // 在v1.begin()迭代器所在的位置插入100
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);  // 在v1.begin()迭代器所在的位置插入2个1000
    printVector(v1);

    // 删除
    v1.erase(v1.begin());  // 在v1.begin()迭代器所在的位置删除其索引的数据
    printVector(v1);

    v1.erase(v1.begin(), v1.end());  // 类似于清空
    printVector(v1);

    // 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}