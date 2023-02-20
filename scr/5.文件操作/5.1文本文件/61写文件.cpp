#include<iostream>
using namespace std;
#include<fstream>



void test01()
{
    // 创建流对象
    ofstream ofs;

    // 指定打开方式打开文件
    ofs.open("text.txt", ios::out);

    // 写内容
    ofs << "Name: Like" << endl; 
    ofs << "性别： 男" << endl;

    // 关闭文件
    ofs.close();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}