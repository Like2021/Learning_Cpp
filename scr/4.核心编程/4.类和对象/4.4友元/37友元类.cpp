#include<iostream>
using namespace std;
#include<string>

class Building
{
    // 友元 类作为友元
    friend class GoodGay;
    
    public:

    Building();

    string m_SittingRoom;  // 客厅

    private:
    string m_BedRoom;  // 卧室

};

// 类做友元
class GoodGay
{
    public:
    GoodGay();

    void visit();  // 参观函数 访问Building中的属性

    Building *building;
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
    cout << "访问: " << building->m_BedRoom  << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}