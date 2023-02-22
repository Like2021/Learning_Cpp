#include "workerManager.h"

// 构造函数
WorkerManager::WorkerManager()
{

}

// 展示菜单
void WorkerManager::Show_Menu()
{
    cout << "******** 欢迎使用职工管理系统！ ********" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 析构函数
WorkerManager::~WorkerManager()
{

}