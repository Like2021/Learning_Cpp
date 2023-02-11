#include<iostream>
using namespace std;

// 前置递增是先++，再操作
// 后置递增是先操作，再++

class MyInteger
{
    friend ostream& operator<< (ostream &cout, MyInteger myint);  // 友元，类外访问私有属性
    
    private:
    int m_Num;

    public:
    MyInteger()
    {
        m_Num = 0;
    }

    // 重载前置++运算符
    // 不返回引用的话，对自定义数据递增只能进行一次
    MyInteger& operator++()
    {
        m_Num++;

        return *this;  // 将自身解引用返回
    }
    
    // 重载后置++运算符
    // 函数返回值类型不能区分重载函数,加个int
    // int代表占位参数，可以区分前置和后置递增
    // 返回的是值，因为它返回的是局部对象，不能返回引用，局部对象会释放
    MyInteger operator++(int)
    {
        // 先记录结果
        MyInteger temp = *this;
    
        // 再递增
        m_Num++;
        
        // 返回记录的结果
        return temp;
    }

};

// 左移运算符重载
ostream& operator<< (ostream &cout, MyInteger myint)  // 这里自定义数据就不需要使用引用传递了，不然后置++会出错，因为它返回的是值
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;

    cout << ++myint << endl;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    // test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    return 0;

}