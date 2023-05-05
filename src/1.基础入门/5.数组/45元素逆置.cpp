#include<iostream>
using namespace std;

void swap(int *arr, int size)
{
    // start起始元素的下标
    // end末尾元素的下标
    for (int start = 0, end = size -1; start < end; start++, end--)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}

void swap02(int *arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // 元素互换
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // 更新下标
        start++;
        end--;
    }
}

void test01()
{
    // 初始化数组和数组长度
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 打印逆置之前的数组
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 元素逆置
    swap02(arr, size);

    // 打印逆置之后的数组
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}