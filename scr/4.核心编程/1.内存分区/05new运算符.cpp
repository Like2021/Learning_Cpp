#include<iostream>
using namespace std;

int * func()
{
    //在堆区创建一个整型的数据
    //new返回的是 数据类型的指针
    int * p = new int(10);
    return p;
}

void test01()
{
    int * p = func();
    //堆区的数据由程序员管理和释放
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    delete p;//释放
    cout << *p << endl;
}

void test02()
{
    //创建10整型数据的数组,在堆区
    int * arr = new int[10];//10代表数组有10个元素
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;//给10个元素赋值  100~109
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;//打印数组
    }
    //释放堆区数组,要加[]
    delete[] arr;
}

int main()
{
    test02();
}