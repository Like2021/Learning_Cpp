#include<iostream>
using namespace std;



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

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}