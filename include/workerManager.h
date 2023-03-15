#pragma once
#include<iostream>
using namespace std;

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

class WorkerManager
{
    public:

    // 构造函数
    WorkerManager();

    // 展示菜单
    void Show_Menu();

    // 退出功能
    void exitSystem();

    // 记录职工的人数
    int m_EmpNum;

    // 记录职工数组的指针
    Worker ** m_EmpArray;

    // 添加职工
    void Add_Emp();

    // 析构函数
    ~WorkerManager();
};