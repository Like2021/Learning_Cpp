#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// 动态增长内存，策略，将存放内存的数据放在堆上

// 容量capacity 表示可以存放多少元素
// size 记录当前数组中具体的元素个数

typedef struct DYNAMICARRAY
{
    int * pAddr;  // 存放数据的地址
    int size;  // 当前有多少个元素
    int capacity;  // 当前容器最大容纳元素个数
}Dynamic_Array;

// 对结构体操作的函数

// 初始化
Dynamic_Array* Init_Array();

// 插入
void PushBack_Array(Dynamic_Array* arr, int value);

// 根据位置删除
void RemoveByPos_Array(Dynamic_Array* arr, int pos);

// 根据值删除
void RemoveByvalue_Array(Dynamic_Array* arr, int value);

// 释放动态数组的内存
void FreeSpace_Array(Dynamic_Array* arr);

// 查找
int Find_Array(Dynamic_Array* arr, int value);

// 打印
void Print_Array(Dynamic_Array* arr);

// 清空数组
void Clear_Array(Dynamic_Array* arr);

// 获得动态数组的容量
int Capacity_Array(Dynamic_Array* arr);

// 获得动态数组当前元素个数
int Size_Array(Dynamic_Array* arr);

// 根据位置获得某个位置元素
int At_Array(Dynamic_Array* arr, int pos);

#endif