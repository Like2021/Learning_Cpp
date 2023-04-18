#include<iostream>
using namespace std;
#include<fstream>

class Person
{
    public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    // 创建流对象
    // ofstream ofs;
    ofstream ofs("person.txt", ios::out | ios::binary);

    // 指定打开方式打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    // 写内容
    Person p = {"Like", 23};
    ofs.write((const char *)&p, sizeof(Person));

    // 关闭文件
    ofs.close();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}