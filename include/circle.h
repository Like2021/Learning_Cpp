#pragma once
#include<iostream>
using namespace std;
#include"point.h"

// 圆类
class Circle
{
    private:
    int m_R; //半径
    Point m_center;

    public:
    // 公共接口
    void setR(int r);
    int getR();
    void setCenter(Point center);
    Point getCenter();

};