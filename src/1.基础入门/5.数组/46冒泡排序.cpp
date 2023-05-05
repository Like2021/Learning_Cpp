#include<iostream>
using namespace std;

void test01()
{
    int arr[9] = {2, 4, 0, 5, 3, 6, 8, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << endl;

    // 总共排序轮数为元素个数 - 1
    for (int i = 0; i < size -1; i++)
    {
        // 内层循环对比
        // 对比次数为元素个数 - 当前轮数 - 1
        for (int j = 0; j < size - i -1; j++)
        {
            // 如果第一个数字比第二个数字大，交换两个数字
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 排序结果
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