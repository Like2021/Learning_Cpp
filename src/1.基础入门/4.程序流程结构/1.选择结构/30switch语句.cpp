#include<iostream>
using namespace std;
#include<string>


void test01()
{
    // 给电影打分

    // 1.提示用户给电影进行评分
    cout << "请给电影进行打分: " << endl;

    // 2.用户开始进行打分
    // int score;
    char c;
    // int score = 0;
    cin >> c;
    cout << "您给的分数为: " << c << endl;

    // 3.根据打分输入评价
    switch(c)
    {
        case 'a':
        cout << "经典电影" << endl;
        break;  // 跳出当前分支，不然会一直往下运行

        // case 9:
        // cout << "经典电影" << endl;
        // break;

        // case 8:
        // cout << "非常好的电影" << endl;
        // break;

        // case 7:
        // cout << "非常好的电影" << endl;
        // break;

        // case 6:
        // cout << "一般电影" << endl;
        // break;

        // case 5:
        // cout << "一般电影" << endl;
        // break;

        default:
        cout << "烂片" << endl;
        break;
    }

    // if和switch的区别？
    // switch只能判断int和字符型，不可以是个区间
    // switch效率高，结构清晰
}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}