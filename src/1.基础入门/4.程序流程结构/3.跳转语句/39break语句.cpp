#include<iostream>
using namespace std;



void test01()
{
    // 跳出选择结构或者循环结构
    // 1.出现在switch条件语句中，作用是终止case并跳出switch
    int select = 0;
    cin >> select;
    switch (select)
    {
        case 2:
        cout << "case2: " << select << endl;
        break;

        case 1:
        cout << "case1: " << select << endl;
        break;  // 退出switch语句

        default:
        cout << "输入是: " << select << endl;
        break;
    }  
}

void test02()
{
    // 2.出现在循环语句中，作用是跳出当前循环
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)  // 如果i等于5，跳出循环
        {
            break;
        }
        cout << i << endl;
    }
}

void test03()
{
    // 3.出现在嵌套循环中，作用是跳出最近的内层循环语句
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)  // 如果j等于5，退出内层循环
            {
                break;
            }
            cout << " * ";
        }
        cout << endl;
    }
}

int main()
{
    // test01();
    // test02();
    test03();

    system("read -p 'Press Enter to continue...' var");
}