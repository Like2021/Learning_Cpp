#include<iostream>
using namespace std;
#include"workerManager.h"

// #include"worker.h"
// #include"employee.h"
// #include"manager.h"
// #include"boss.h"

int main()
{
    // 测试代码
    // Worker * worker = NULL;
    // worker = new Employee(1, "Like", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(2, "Like", 2);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(3, "Like", 3);
    // worker->showInfo();
    // delete worker;

    WorkerManager wm;

    int choice = 0;
    while(true)
    {
        // 展示菜单
        wm.Show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch(choice)
        {
            case 0:  // 退出系统
            wm.exitSystem();
            break;
            case 1:  // 添加职工
            wm.Add_Emp(); 
            break;
            case 2:  // 显示职工
            break;
            case 3:  // 删除职工
            break;
            case 4:  // 修改职工
            break;
            case 5:  // 查找职工
            break;
            case 6:  // 排序职工
            break;
            case 7:  // 清空职工
            break;
            default:
            system("clear");
            break;
        }
    }

    wm.Show_Menu();

    // system("read -p 'Press Enter to continue...' var");
    // system("read var");


    // return 0;

}