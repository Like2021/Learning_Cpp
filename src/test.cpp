#include<iostream>
using namespace std;

// 测试const的使用
void test01()
{
    int a = 10;
    int b = 20;

    const int * p = &a;

    // int * const p = &a;

    p = &b;

    // *p = 20;

    cout << *p << endl;
}

void Algorithm02()
{
    int sum = 0, n = 100;
    sum = (1 + n) * n / 2;
    printf("%d\n", sum);
}

void test02()
{
    Algorithm02();
}

int main()
{
    // test01();
    test02();

    system("read -p 'Press Enter to continue...' var");
}