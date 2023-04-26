#include<iostream>
using namespace std;

// 不在函数体内的变量，叫全局变量
int g_a = 10;  // g->global
int g_b = 10;

// const修饰的全局变量 全局常量
const int c_g_a = 10;
const int c_g_b = 10;


void test01()
{
    // 全局区 存放有 全局变量和静态变量
    // 还有除了const修饰的局部常量之外的其他常量

    // 创建普通局部变量，创建在函数体内的变量  都叫局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址: " << (long)&a << endl;
    cout << "局部变量b的地址: " << (long)&b << endl;

    cout << "全局变量a的地址: " << (long)&g_a << endl;
    cout << "全局变量b的地址: " << (long)&g_b << endl;

    // 静态变量 有static
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量s_a地址为: " << (long)&s_a << endl;
	cout << "静态变量s_b地址为: " << (long)&s_b << endl;

    // 常量 分为字符串常量和const修饰的常量
    
    // 字符串常量
	cout << "字符串常量地址为: " << (long)&"hello world" << endl;
	cout << "字符串常量地址为: " << (long)&"hello world1" << endl;
    
    // const修饰的常量 分为const修饰的全局变量和const修饰的局部变量
	cout << "全局常量c_g_a地址为: " << (long)&c_g_a << endl;
	cout << "全局常量c_g_b地址为: " << (long)&c_g_b << endl;

    // const修饰的局部变量不在全局区
    const int c_l_a = 10;  // l->local
    const int c_l_b = 10;

	cout << "局部常量c_l_a地址为: " << (long)&c_l_a << endl;
	cout << "局部常量c_l_b地址为: " << (long)&c_l_b << endl;

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}