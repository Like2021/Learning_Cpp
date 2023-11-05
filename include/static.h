#ifndef _STATIC_H_
#define _STATIC_H_
#include <iostream>

class Base {
    public:
    Base(int m_A1){
        this->m_A1 = m_A1;
    }
    void m_func1();
    static void m_func2();
    int m_A1;
    static int m_A2;
};

#endif