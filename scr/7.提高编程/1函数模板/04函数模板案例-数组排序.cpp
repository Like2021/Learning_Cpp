#include<iostream>
using namespace std;

// 实现通用 对数组进行排序的函数
// 规则 从大到小
// 选择排序
// 测试 char 数组、 int 数组

// 交换模板
template<class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序算法
template<class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;  // 认定最大值的下标
        for (int j = i+1; j < len; j++)
        {
            // 认定的最大值，比遍历出的数值要小，说明j下标代表的元素是最大值
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            // 如果进行了max = j;
            // 交换max 和 i的元素
            mySwap(arr[max], arr[i]);
        }
    }
}

// 打印数组的模板
template<class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    // 测试char数组
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}

void test02()
{
    // 测试int 数组
    int intArr[] = {1, 4, 5, 6, 8, 2};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main()
{
    test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}