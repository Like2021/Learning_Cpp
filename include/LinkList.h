#pragma once

#include<stdio.h>
#include<stdlib.h>

// 链表节点
typedef struct LINKNODE
{
    void* data;  // 无类型指针，指向任何类型的数据

    struct LINKNODE* next;
}LinkNode;

// 链表结构体
typedef struct LINKLIST
{
    LinkNode* head;
    int size;

    // 没有容量的概念
}LinkList;

// 打印函数指针
typedef void(*PRINTLINKNODE)(void*);

// 初始化链表
LinkList* Init_LinkList();

// 指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data);

// 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos);

// 获得链表的长度
int Size_LinkList(LinkList* list);

// 查找
int Find_LinkList(LinkList* list, void* data);

// 返回第一个节点
void* Front_LinkList(LinkList* list);

// 打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print);

// 释放链表内存
void FreeSpace_LinkList(LinkList* list);

