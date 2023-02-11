#include<iostream>
using namespace std;
#include<string>

class Building;

// 类做友元
class GoodGay
{
    public:
    GoodGay();

    void visit();  // 参观函数 访问Building中的私有属性
    void visit2();

    Building *building;
};

class Building
{
    // 成员函数做友元
    friend void GoodGay::visit();

    public:

    Building();

    string m_SittingRoom;  // 客厅

    private:
    string m_BedRoom;  // 卧室

};

// 类外实现类内函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    // 创建建筑物对象
    building = new Building;
}

void GoodGay::visit()
{
    cout << "访问: " << building->m_SittingRoom << endl;
    cout << "visit访问: " << building->m_BedRoom  << endl;
}

void GoodGay::visit2()
{
    cout << "访问: " << building->m_SittingRoom << endl;
    // cout << "visit2访问: " << building->m_BedRoom  << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}