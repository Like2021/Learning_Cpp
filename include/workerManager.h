#pragma once
#include<iostream>
using namespace std;

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "scr/6.职工管理系统/empFile.txt"

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

    // 保存文件
    void save();

    // 标志文件是否为空
    bool m_FileIsEmpty;

    // 统计人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 析构函数
    ~WorkerManager();
};