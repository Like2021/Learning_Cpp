#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty())  // 返回为true，代表容器为空
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量: " << v1.capacity() << endl;  // 16
        cout << "v1的大小: " << v1.size() << endl;  // 10
    }

    // 重新指定大小
    v1.resize(15);  // 多出的位置用0默认填充
    v1.resize(15, 100);  // 多出的位置用100填充（重载的版本）
    printVector(v1);

    v1.resize(5);
    printVector(v1);  // 如果重新指定的比原来短，超出的部分会被删除
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}