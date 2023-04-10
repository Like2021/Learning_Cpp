#include<iostream>
using namespace std;
#include<fstream>
#include<string>


void test01()
{
    // 创建流对象
    ifstream ifs;

    // 打开文件并判断文件是否打开成功
    ifs.open("text.txt", ios::in);
    
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 读数据
    // 第一种
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    // 第二种
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }

    // 第四种
    char c;
    while ((c = ifs.get()) != EOF)  // EOF == end of file
    {
        cout << c;
    }

    // 关闭文件
    ifs.close();
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");

    return 0;

}