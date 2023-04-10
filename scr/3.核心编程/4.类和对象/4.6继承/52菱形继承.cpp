#include<iostream>
using namespace std;

// 动物类
class Animal
{
    public:

    int m_Age;
};

// 利用虚继承 解决菱形继承的问题
// 继承之前 加上关键字 virtual 变成虚集成
// Animal类称为虚基类

// 羊类
class Sheep : virtual public Animal{};

// 驼类
class Tuo : virtual public Animal{};

// 羊驼类
class SheepTuo : public Sheep, public Tuo{};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 19;

    // vbptr指向vbtable 虚基类表

    // v-virtual
    // b-base
    // ptr-pointer

    // 当菱形继承，两个父类拥有相同数据，需要加作用域区分
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

    // 这份数据，只要一份就可以了
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}