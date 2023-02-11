#include<iostream>
using namespace std;


// 占位参数
// 返回值类型 函数名(数据类型){}
void func(int a, int)// 或者int = 10
{
    cout << "this is func." << endl;
}

int main()
{
    func(10, 10);
}