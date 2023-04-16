#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>

/*
* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息的插入  key(部门编号) value(员工)
* 分部门显示员工信息
*/

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
    public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>&v)
{
    // 创建10个员工
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand() % 10000 + 10000;  // 10000~19999

        // 将员工放入容器中
        v.push_back(worker);
    }
}

// 员工分组
void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3;  // 0,1,2

        // 将员工插入分组中
        // key 为部门编号 value为部门员工
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker>&m)
{
    cout << "策划部门: " << endl;

    // 找一下key为0
    multimap<int, Worker>::iterator pos = m.find(CEHUA);

    // 统计一下key为0的个数
    int count = m.count(CEHUA);
    int index = 0;

    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
    }

    cout << "美术部门: " << endl;

    // 美术的key为1
    multimap<int, Worker>:: iterator pos1 = m.find(MEISHU);

    // 统计key为1的个数
    count = m.count(MEISHU);
    index = 0;

    for (; pos1 != m.end() && index < count; pos1++, index++)
    {
        cout << "姓名: " << pos1->second.m_Name << " 工资: " << pos1->second.m_Salary << endl;
    }

    cout << "研发部门: " << endl;

    // 研发的key为3
    multimap<int, Worker>::iterator pos2 = m.find(MEISHU);

    // 统计研发的人员个数
    count = m.count(YANFA);
    index = 0;

    for (; pos2 != m.end() && index < count; pos2++, index++)
    {
        cout << "姓名: " << pos2->second.m_Name << " 工资: " << pos2->second.m_Salary << endl; 
    }
}

void test01()
{
    // 1.创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);
     
    // 测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    //     cout << "name = " << it->m_Name << " salary = " << it->m_Salary << endl;
    // }

    // 2.员工分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker, mWorker); 

    //3.分组显示员工
    showWorkerByGroup(mWorker);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}