#include<iostream>
using namespace std;

class Cube
{
    // 属性
    // 长宽高
    private:
    int m_L;
    int m_W;
    int m_H;

    // 行为
    // 设置和获取长宽高
    public:
    void setL(int L)
    {
        m_L = L;
    }

    int getL()
    {
        return m_L;
    }

    void setW(int W)
    {
        m_W = W;
    }

    int getW()
    {
        return m_W;
    }

    void setH(int H)
    {
        m_H = H;
    }

    int getH()
    {
        return m_H;
    }

    // 获取立方体面积
    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_H * m_W;
    }

    // 获取立方体体积
    int calculateV()
    {
        return m_L * m_W * m_H;
    }

    // 利用成员函数判断两个立方体是否相等
    void isSameByClass(Cube &c)
    {
        if(m_L == c.getL() && m_H == c.getH() && m_W == c.getW())
        {
            cout << "成员函数判断:相等" << endl;
        }
        else
        {
            cout << "成员函数判断:不相等" << endl;
        }
    }
};

bool isSame(Cube &c1, Cube &c2)
{
    if(c1.getH()==c2.getH() && c1.getL()==c2.getL() && c1.getW()==c2.getW())
    {
        return true;
    }

    return false;
};

int main()
{
    Cube c1;
    c1.setL(10);
    c1.setH(20);
    c1.setW(30);
    cout << c1.calculateS() << endl;
    cout << c1.calculateV() << endl;

    Cube c2;
    c2.setH(20);
    c2.setL(10);
    c2.setW(30);

    bool result = isSame(c1, c2);

    if (result)
    {
        cout << "c1与c2相等" << endl;
    }
    else
    {
        cout << "不相等" << endl; 
    }
    
    c1.isSameByClass(c2);

    // system("pause");

    return 0;

}