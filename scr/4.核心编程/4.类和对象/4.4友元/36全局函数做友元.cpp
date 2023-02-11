#include<iostream>
using namespace std;
#include<string>

class Building
{
    // 友元 全局函数作为友元
    friend void goodGay(Building *building);

    public:

    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

    string m_SittingRoom;  // 客厅

    private:
    string m_BedRoom;  // 卧室

};

// 全局函数
// void goodGay(Building &building)
void goodGay(Building *building)
{
    cout << "访问: " << building->m_SittingRoom << endl;

    cout << "访问: " << building->m_BedRoom << endl; 
}

void test01()
{
    Building building;
    goodGay(&building);
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}