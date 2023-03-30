#include<iostream>
using namespace std;

template<class T>
class Base
{
    T m;
};

// class Son :public Base  // 错误，必须要知道父类中的T的类型
class Son : public Base<int>
{

};

void test01()
{
    Son s1;
}

// 如果想灵活指定T的类型，子类也需要变成类模板
template<class T1, class T2>
class Son2 : public Base<T2>
{
    public:
    Son2()
    {
        cout << typeid(T1).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son2<int, char>s;
}

int main()
{
    test01();
    test02();

    // system("read -p 'Press Enter to continue...' var");

    // return 0;

}