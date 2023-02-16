#include<iostream>
using namespace std;

// 父类
class AbstractDrinking
{
    public:

    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 倒入杯中
    virtual void PourIncCup() = 0;

    // 加入辅料
    virtual void AddSomething() =0;

    // 制作饮品
    void makeDrink()
    {
        Boil();
        Brew();
        PourIncCup();
        AddSomething();
    }
};

// 子类-冲泡咖啡
class Coffee : public AbstractDrinking
{
    public:

    // 重写纯虚函数
    // 煮水
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }

    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }

    // 倒入杯中
    virtual void PourIncCup()
    {
        cout << "倒入杯中" << endl;
    }

    // 加入辅料
    virtual void AddSomething()
    {
        cout << "加入牛奶和糖" << endl;
    }
};

// 子类-煮茶
class Tea : public AbstractDrinking
{
    public:

    // 重写纯虚函数
    // 煮水
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }

    // 冲泡
    virtual void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }

    // 倒入杯中
    virtual void PourIncCup()
    {
        cout << "倒入杯中" << endl;
    }

    // 加入辅料
    virtual void AddSomething()
    {
        cout << "加入枸杞" << endl;
    }
};

// 制作函数
void doWork(AbstractDrinking * abs)
{
    abs->makeDrink();
    delete abs;
}

void test01()
{
    // 制作咖啡
    doWork(new Coffee);

    // 煮茶
    doWork(new Tea);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}