#include "workerManager.h"

// 构造函数
WorkerManager::WorkerManager()
{
    // 初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

// 展示菜单
void WorkerManager::Show_Menu()
{
    cout << "******** 欢迎使用职工管理系统！ ********" << endl;
    cout << endl;
}

// 退出系统
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量： " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 添加
        // 计算添加后新空间大小
        int newSize = this->m_EmpNum + addNum;  // 新空间人数 = 原来的人数 + 新增的人数

        // 开辟新空间
        Worker ** newSpace = new Worker*[newSize];

        // 将原来空间下的数据，拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 拷贝好原数据之后，批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;  // 职工编号
            string name;  // 职工姓名
            int dSelect;  // 部门选择

            cout << "请输入第 " << i+1 << " 个新职工编号:" << endl;
            cin >> id;

            cout << "请输入第 " << i+1 << " 个新职工姓名:" << endl;
            cin >> name;

            cout << "请选择该职工岗位: " << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
                case 1:
                worker = new Employee(id, name, 1);
                break;

                case 2:
                worker = new Manager(id, name, 2);
                break;

                case 3:
                worker = new Boss(id, name, 3);
                break;

                default:
                break;
            }

            // 将创建的职工指针，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        // 释放原有的保存空间
        delete [] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新一下新的职工人数
        this->m_EmpNum = newSize;

        // 提示添加成功
        cout << "成功添加" << addNum << endl;
    }
    else
    {
        cout << "输入有误" << endl;
    }

    // 按任意键，返回上一级
    system("clear");
    system("read -p 'Press Enter to continue...' var");

}

// 析构函数
WorkerManager::~WorkerManager()
{

}