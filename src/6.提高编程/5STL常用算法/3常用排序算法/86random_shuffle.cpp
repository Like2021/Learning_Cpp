#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<ctime>

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    srand((unsigned int)time(NULL));
    
    vector<int>v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 利用洗牌算法打乱顺序，默认每次打乱都是一样的，可以添加随机种子 完成真实随机
    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}