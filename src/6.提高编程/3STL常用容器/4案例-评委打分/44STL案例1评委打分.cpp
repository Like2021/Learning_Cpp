#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
*/
// 1. 创建五名选手，放到vector中
// 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序，去除最高和最低分
// 4. deque容器遍历一遍，累加总分
// 5. 获取平均分

class Person
{
    public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;  // 姓名
    int m_Score;  // 平均分
};

void createPerson(vector<Person>&v)  // 一定要引用的方式传递，不然修改不了实参
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        // 将创建的对象放入容器中
        v.push_back(p);
    }
}

// 打分函数
void setScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 把10个评分打分存到deque容器中
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;  // rand() % 41 即0~40
            d.push_back(score);
        }

        // 可视化打分结果
        // cout <<  it->m_Name << "打分: " << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;

        // 对分数进行排序
        sort(d.begin(), d.end());  // 需要包含algorithm头文件

        // 去除最高和最低分
        d.pop_back();
        d.pop_front();

        // 取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }

        int avg = sum / d.size();

        // 将平均分赋值给选手
        it->m_Score = avg;
    }
}

// 打印分数
void showScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->m_Name << "平均分: " << it->m_Score << endl;
    }
}

void test01()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    // 1.创建5名选手
    vector<Person>v;
    createPerson(v);

    // 测试
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << (*it).m_Name << " " << (*it).m_Score << endl;
    // }

    // 2.给5名选手打分
    setScore(v);

    // 3.显示最后得分
    showScore(v);

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}