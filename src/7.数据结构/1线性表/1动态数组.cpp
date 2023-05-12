// #include<stdlib.h>
// #include<stdio.h>
#include<string.h>

#include"DynamicArray.h"

void test01()
{
    // 初始化动态数组
    Dynamic_Array* myArray = Init_Array();
    // 初始化的同时，打印数组容量
    printf("数组容量: %d\n", Capacity_Array(myArray));
    printf("数组大小: %d\n", Size_Array(myArray));

    // 插入元素
    for (int i = 0; i < 30; i++)
    {
        PushBack_Array(myArray, i);
    }

    printf("数组容量: %d\n", Capacity_Array(myArray));
    printf("数组大小: %d\n", Size_Array(myArray));

    // 打印
    Print_Array(myArray);

    // 删除
    RemoveByPos_Array(myArray, 0);
    RemoveByPos_Array(myArray, 10);

    Print_Array(myArray);

    // 查找5的位置
    int pos = Find_Array(myArray, 5);
    
    printf("查找到5,在%d,值为%d\n", pos, At_Array(myArray, pos));


    // 销毁
    FreeSpace_Array(myArray);
}

int main(void)
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}