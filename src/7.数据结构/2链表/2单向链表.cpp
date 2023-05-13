#include"LinkList.h"
#include<iostream>
using namespace std;

typedef struct PERSON
{
    char name[64];
    int age;
    int score;
}Person;

// 打印函数
void MyPrint(void* data)
{
    Person* p = (Person*)data;
    printf("Name: %s Age: %d Score:%d\n", p->name, p->age, p->score);
}

void test01()
{
    // 创建一个链表
    LinkList* list = Init_LinkList();

    // 创建数据
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"bbb", 28, 99};
    Person p3 = {"ccc", 38, 101};
    Person p4 = {"ddd", 48, 97};
    Person p5 = {"eee", 58, 69};

    // 数据插入链表
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    // 打印
    Print_LinkList(list, MyPrint);

    // 删除
    RemoveByPos_LinkList(list, 3);
    printf("--------------------------\n");
    Print_LinkList(list, MyPrint);

    // 返回第一个节点的数据
    Person* result = (Person*) Front_LinkList(list);
    printf("--------------------------\n");
    printf("Name: %s Age: %d Score: %d\n", result->name, result->age, result->score);


    // 销毁
    FreeSpace_LinkList(list);

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}