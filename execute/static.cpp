#include "static.h"

int Base::m_A2 = 10;

void Base::m_func1() {
    std::cout << "非静态成员函数" << std::endl;
}

void Base::m_func2() {
    std::cout << "静态成员函数" << std::endl;
}