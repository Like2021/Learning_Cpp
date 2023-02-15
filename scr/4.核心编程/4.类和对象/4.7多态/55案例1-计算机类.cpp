#include<iostream>
using namespace std;
#include<string>

// 多态的优点
// 代码组织结构清晰
// 可读性强
// 利于前期和后期的扩展以及维护

// 普通写法
class Calculator
{
    public:

    int getResult(string oper)
    {
        if(oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if(oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if(oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else
        {
            return 0;
        }
        // 如果想扩展新的功能，需要修改源码
        // 在真实开发中，提倡开闭原则
        // 对扩展进行开放，对修改进行关闭
    }

    int m_Num1;
    int m_Num2;
};

// 多态实现

// 实现计算器抽象类
class AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
    public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
    public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    // 多态使用条件
    // 父类指针或者引用指向子类对象

    // 加法运算
    AbstractCalculator * abc = new AddCalculator;  // new出来的对象，创建在堆区
    abc->m_Num1 = 15;
    abc->m_Num2 = 20;

    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    // 用完后销毁堆区数据，但仍是父类AbstractCalculator的指针
    delete abc;

    //减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 15;
    abc->m_Num2 = 20;

    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    // 乘法运算
    abc = new MulCalculator;
    abc->m_Num1 = 15;
    abc->m_Num2 = 20;

    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

void test01()
{
    // 创建一个计算器对象
    Calculator c;
    c.m_Num1 = 20;
    c.m_Num2 = 10;

    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}