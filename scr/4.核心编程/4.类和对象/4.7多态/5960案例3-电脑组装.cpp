#include<iostream>
using namespace std;

// CPU类
class CPU
{
    public:

    // 抽象计算函数
    virtual void calculate() = 0;
};

// 显卡类
class VideoCard
{
    public:

    // 抽象显示函数
    virtual void display() = 0;
};

// 内存条类
class Memory
{
    public:

    //抽象存储函数
    virtual void storage() = 0;
};

// 电脑类
class Computer
{
    public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_Cpu = cpu;
        m_Vc = vc;
        m_Mem = mem;
    }

    // 提供工作函数
    void work()
    {
        m_Cpu->calculate();
        m_Vc->display();
        m_Mem->storage();
    }

    // 提供析构函数，释放3个电脑零件
    ~Computer()
    {
        if(m_Cpu != NULL)
        {
            delete m_Cpu;
            m_Cpu = NULL;
        }

        if(m_Vc != NULL)
        {
            delete m_Vc;
            m_Vc = NULL;
        }

        if(m_Mem != NULL)
        {
            delete m_Mem;
            m_Mem = NULL;
        }
    }

    private:

    CPU *m_Cpu;
    VideoCard *m_Vc;
    Memory * m_Mem;
};

// 具体类
class IntelCpu : public CPU
{
    public:

    virtual void calculate()
    {
        cout << "Intel的cpu工作" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
    public:

    virtual void display()
    {
        cout << "Intel的显卡工作" << endl;
    }
};

class IntelMemory : public Memory
{
    public:

    virtual void storage()
    {
        cout << "Intel的内存条工作" << endl;
    }
};

void test01()
{
    // CPU *intelCpu = new IntelCpu
    // VideoCard *intelCard = new IntelVideoCard;
    // Memory *intelMem = new IntelMemory;

    // 创建第一台电脑
    Computer *computer1 = new Computer(new IntelCpu, new IntelVideoCard, new IntelMemory);
    // Computer *computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}