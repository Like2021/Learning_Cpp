#include<iostream>
using namespace std;

// 数组的下标是从0开始的
// 数组内存空间的地址是连续的

int array_find(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {

        if (arr[i] == target)
        {
            return i;
        }
    }

    // 没找到
    return -1;
}

void test01()
{
    int arr[4] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int pos = array_find(arr, size, 3);
    cout << pos << endl;

    
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}