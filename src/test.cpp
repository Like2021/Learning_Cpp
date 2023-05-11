#include<iostream>
using namespace std;
#include<vector>

// 测试const的使用
void test01()
{
    int a = 10;
    int b = 20;

    const int * p = &a;

    // int * const p = &a;

    p = &b;

    // *p = 20;

    cout << *p << endl;
}

void Algorithm02()
{
    int sum = 0, n = 100;
    sum = (1 + n) * n / 2;
    printf("%d\n", sum);
}

// 测试printf的使用
void test02()
{
    Algorithm02();
}

// 测试vector套娃的size计算
void test03()
{
    vector<vector<int>> testOne(10, vector<int>(11, 0));
    // int size = testOne.size();
    int size = testOne[0].size();
    cout << testOne.size() << endl;
    cout << size << endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    // 1.定义一些记录或者计算的变量
    int m = matrix.size(), n = matrix[0].size();  // 定义两个变量记录矩阵大小，m行n列
    vector<int> result((m*n), 0);  // 定义一个记录取出来元素的容器
    int startX = 0, startY = 0;  // 定义两个记录起始位置的变量
    int offset = 1;  // 定义一个控制遍历每条边长度的变量
    int index = 0;  // 定义一个result用来记录取出元素的索引
    int midX = m / 2, midY = n / 2;  // 定义变量记录中间位置
    int loop = 0;  // 定义一个记录循环次数的变量
    int i, j;


    while (n - offset > 0 && m - offset > 0)
    // 第一步，只要n - offset或者m -offset中有一个== 0，就跳出循环，只剩下里面的单行或者单列的元素
    {          
        // 初始化一下i和j
        i = startX, j =startY;

        // 1.遍历上边
        for (; j < n - offset; j++)  // 例如第一个循环里，如果一行有3个元素，那就遍历出来2个
        {
            result[index++] = matrix[startX][j];
        }

        // 2.遍历右边
        for (; i < m - offset; i++)  // 例如第一个循环里，如果一列有4个元素，那就遍历出来3个
        {
            result[index++] = matrix[i][j];
        }

        // 3.遍历下边
        for (; j > startY; j--)
        {
            result[index++] = matrix[i][j];  // i不变
        }

        // 4.遍历左边
        for (; i > startX; i--)
        {
            result[index++] = matrix[i][startY];  // j已经回到起始的startY了，所以这里填j和startY都可以
        }

        // 更新一些记录的变量
        // 控制每条边遍历长度的变量
        offset += 2;

        // 记录while循环次数
        loop++;

        // 起始位置的更新
        startX++;
        startY++;
    }

    // 第二步，如果m和n都是偶数，则没有单行或者单列，只要有一个不是偶数，就有单行单列

    // 记录单列中的行数索引
    int m_r = startX;

    // 记录单行中的列数索引
    int n_r = startY;
    
    // 奇数列+列数小于行数，出现单列
    if (n % 2 != 0  && m > n)
    {
        //单列所在的列
        
        // 取出单列的元素
        for (int o = 0; o < n - loop * 2; m_r++)
        {
            result[index++] = matrix[m_r][midY];
        }
    }

    // 奇数行+行数小于列数，出现单行
    else if (m % 2 != 0 && m < n)
    {
        // 取出单行的元素
        for (int o = 0; o < n - loop * 2; n_r++)
        {
            result[index++] = matrix[midX][n_r];
        }
    }
    else if (m == n)
    {
        result[index] = matrix[midX][midY];
    }

    // 返回结果
    return result;

}

// 54.螺旋矩阵题, 手撕代码失败
void test04()
{
    vector<vector<int>> m(1, vector<int>(3, 1));
    vector<int> result = spiralOrder(m);

    for (vector<int>::iterator it = result.begin(); it < result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // test01();
    // test02();
    // test03();
    test04();

    system("read -p 'Press Enter to continue...' var");
}