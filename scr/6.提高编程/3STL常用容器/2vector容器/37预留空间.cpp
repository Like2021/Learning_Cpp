#include<iostream>
using namespace std;
#include<vector>

// 减少vector在动态扩展容量是的扩展次数
// reserve(int len) 容器预留len个元素长度，预留位置不初始化，元素不可访问

void test01()
{
    vector<int>v;

    // 解决方法，提前预留好空间
    v.reserve(100000);

    int num = 0;  // 统计内存扩展次数
    int *p = NULL;
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if(p != &v[0])  // 如果指针p不指向v的首地址
        {
            p = &v[0];  // 强制其指向，每次内存扩展，其首地址都会变
            num++;  // 每强制指向一次，就记录+1，即内存扩展次数
        }
    }
    cout << "num = " << num << endl;
}

int main()
{
    test01();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}