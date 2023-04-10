#include<iostream>
using namespace std;



void test01()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}