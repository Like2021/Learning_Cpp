#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"

// 判断点和圆关系
void isInCircle(Circle &c, Point &p)
{
    // 计算距离平方
    int distance =
    (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + 
    (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    // 计算半径的平方
    int rDistance = c.getR() * c.getR();

    // 判断关系
    if(distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if(distance > rDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }

};

int main()
{
    // 实例化圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    // 实例化一个点
    Point p;
    p.setX(20);
    p.setY(0);

    isInCircle(c, p);

    // system("pause");

    return 0;

}