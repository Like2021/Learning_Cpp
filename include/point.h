#pragma once
#include<iostream>
using namespace std;

// 点类
class Point
{
    private:
    int m_X;
    int m_Y;

    public:
    // 公共接口
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
};