#include<iostream>
using namespace std;
#include<string>

const double PI = 3.14;

// 创建类
// 类中的属性和行为 统称为成员
// 属性 成员属性或者成员变量
// 行为 成员函数或者成员方法
class Circle
{
public:
    //属性 半径
    int m_r;

    //行为 获得圆的周长
    double calculateZC()
    {
        return 2 * PI * m_r;
    }

};

class Student
{
    public:
    // 属性 姓名和学号
    string m_name;
    int number;

    // 行为 显示学生的姓名和学号
    void showName()
    {
        cout << "name: " << m_name << endl;
    }
    void showNumber()
    {
        cout << "number: " << number << endl;
    }

    // 给姓名赋值
    void setName(string name)
    {
        m_name = name;
    }
};

int main()
{
    // 通过圆类 创建具体的圆(对象)
    Circle c1;
    // 给对象的属性进行赋值操作
    c1.m_r = 10;

    cout << "周长为: " << c1.calculateZC() << endl;

    Student s1;
    // s1.m_name = "Like";
    s1.setName("like");
    s1.number = 3102321;

    s1.showName();
    s1.showNumber();
}