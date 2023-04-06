#include<iostream>
using namespace std;
#include<vector>

// 实现两个容器内元素进行互换

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 基本使用
void test01()
{
    vector<int>v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    
    cout << "交换前: " << endl;
    printVector(v1);

    vector<int>v2;
    for(int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }

    printVector(v2);

    cout << "交换后: " << endl;

    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//实际用途
//巧用swap可以收缩内存空间
void test02()
{
    vector<int>v;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;

    v.resize(3);  //重新指定大小

    cout << "v的容量: " << v.capacity() << endl;  // 容量没有改变
    cout << "v的大小: " << v.size() << endl;

    // 利用swap
    // vector<int>(v) 匿名对象 用v的大小初始化 匿名对象的大小和容量
    // .swap(v) 容器交换 交换后，匿名对象被回收（匿名对象的特性）
    vector<int>(v).swap(v);

    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;
}

int main()
{
    // test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}