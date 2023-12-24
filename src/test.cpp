#include <iostream>
using namespace std;
#include <limits>
#include <memory>
#include <vector>

#include "static.h"

// 测试const的使用
void test01() {
  int a = 10;
  int b = 20;

  const int* p = &a;

  // int * const p = &a;

  p = &b;

  // *p = 20;

  cout << *p << endl;
}

void Algorithm02() {
  int sum = 0, n = 100;
  sum = (1 + n) * n / 2;
  printf("%d\n", sum);
}

// 测试printf的使用
void test02() { Algorithm02(); }

// 测试vector套娃的size计算
void test03() {
  vector<vector<int>> testOne(10, vector<int>(11, 0));
  // int size = testOne.size();
  int size = testOne[0].size();
  cout << testOne.size() << endl;
  cout << size << endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  // 1.定义一些记录或者计算的变量
  int m = matrix.size(),
      n = matrix[0].size();  // 定义两个变量记录矩阵大小，m行n列
  vector<int> result((m * n), 0);  // 定义一个记录取出来元素的容器
  int startX = 0, startY = 0;      // 定义两个记录起始位置的变量
  int offset = 1;  // 定义一个控制遍历每条边长度的变量
  int index = 0;   // 定义一个result用来记录取出元素的索引
  int midX = m / 2, midY = n / 2;  // 定义变量记录中间位置
  int loop = 0;                    // 定义一个记录循环次数的变量
  int i, j;

  while (n - offset > 0 && m - offset > 0)
  // 第一步，只要n - offset或者m -offset中有一个==
  // 0，就跳出循环，只剩下里面的单行或者单列的元素
  {
    // 初始化一下i和j
    i = startX, j = startY;

    // 1.遍历上边
    for (; j < n - offset;
         j++)  // 例如第一个循环里，如果一行有3个元素，那就遍历出来2个
    {
      result[index++] = matrix[startX][j];
    }

    // 2.遍历右边
    for (; i < m - offset;
         i++)  // 例如第一个循环里，如果一列有4个元素，那就遍历出来3个
    {
      result[index++] = matrix[i][j];
    }

    // 3.遍历下边
    for (; j > startY; j--) {
      result[index++] = matrix[i][j];  // i不变
    }

    // 4.遍历左边
    for (; i > startX; i--) {
      result[index++] =
          matrix[i]
                [startY];  // j已经回到起始的startY了，所以这里填j和startY都可以
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
  if (n % 2 != 0 && m > n) {
    // 单列所在的列

    // 取出单列的元素
    for (int o = 0; o < n - loop * 2; m_r++) {
      result[index++] = matrix[m_r][midY];
    }
  }

  // 奇数行+行数小于列数，出现单行
  else if (m % 2 != 0 && m < n) {
    // 取出单行的元素
    for (int o = 0; o < n - loop * 2; n_r++) {
      result[index++] = matrix[midX][n_r];
    }
  } else if (m == n) {
    result[index] = matrix[midX][midY];
  }

  // 返回结果
  return result;
}

// 54.螺旋矩阵题, 手撕代码失败
void test04() {
  vector<vector<int>> m(1, vector<int>(3, 1));
  vector<int> result = spiralOrder(m);

  for (vector<int>::iterator it = result.begin(); it < result.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// 测试容器的遍历打印操作
void test05() {
  // 构造赋值为10个100
  vector<int> testVector(10, 100);

  // 遍历打印
  for (auto testInt : testVector) {
    cout << testInt << " ";
  }
  cout << endl;

  cout << *testVector.end() << endl;
}

// 智能指针
void test06() { std::unique_ptr<int> ptr = std::make_unique<int>(200); }

// static
void test07() {
  Base b(10);
  std::cout << b.m_A1 << std::endl;
  std::cout << Base::m_A2 << std::endl;
  Base::m_func2();
  b.m_func1();
}

// sizeof
void test08() {
  int buffer[3];
  std::cout << "sizeof(buffer): " << sizeof(buffer[0]) << std::endl;
}

// string add
void test09() {
  std::string dirPath("aa");
  std::string aPath("like");
  std::string Path = aPath + dirPath;
  std::cout << Path << std::endl;
}

// test float to int
void test10() {
  float a = 1.211111f;
  float b = 1.211112f;

  int intA = *reinterpret_cast<int*>(&a);
  int intB = *reinterpret_cast<int*>(&b);

  std::cout << "Original float values: a=" << a << ", b=" << b << std::endl;
  std::cout << "Reinterpreted int values: intA=" << intA << ", intB=" << intB
            << std::endl;

  if (intA < intB) {
    std::cout << "intA is less than intB" << std::endl;
  } else if (intA > intB) {
    std::cout << "intA is greater than intB" << std::endl;
  } else {
    std::cout << "intA is equal to intB" << std::endl;
  }
}

void Merge(std::vector<int>& Array, int front, int mid, int end) {
  // 两个子序列
  std::vector<int> leftSubArray(Array.begin() + front, Array.begin() + mid + 1);
  std::vector<int> rightSubArray(Array.begin() + mid + 1,
                                 Array.begin() + end + 1);
  int idxLeft = 0, idxRight = 0;
  // 给两个子序列末尾插入最大值
  leftSubArray.insert(leftSubArray.end(), numeric_limits<int>::max());
  rightSubArray.insert(rightSubArray.end(), numeric_limits<int>::max());
  // 依次保存两个子序列里的最小值
  for (int i = front; i <= end; ++i) {
    if (leftSubArray[idxLeft] < rightSubArray[idxRight]) {
      Array[i] = leftSubArray[idxLeft++];
    } else {
      Array[i] = rightSubArray[idxRight++];
    }
  }
}

void MergeSort(std::vector<int>& Array, int front, int end) {
  if (front >= end) return;
  int mid = (front + end) / 2;
  MergeSort(Array, front, mid);
  MergeSort(Array, mid + 1, end);
  Merge(Array, front, mid, end);
}

void test11() {
  std::vector<int> Array = {10, 5, 3, 6, 9, 1};
  for (auto a : Array) {
    std::cout << "a: " << a << " ";
  }
  std::cout << std::endl;
  MergeSort(Array, 0, Array.size() - 1);
  for (auto a : Array) {
    std::cout << "a: " << a << " ";
  }
  std::cout << std::endl;
}

int Paritition(std::vector<int>& Array, int low, int high) {
  // 1.选取Array[low]为基准元素
  int pivot = Array[low];
  while (low < high) {
    // 2.先从右边开始，找第一个小于pivot的值
    while (low < high && Array[high] >= pivot) {
      --high;
    }
    // 3.将其移动到左边，与pivot换位置
    Array[low] = Array[high];
    // 4.再从左边开始，找地一个大于pivot的值
    while (low < high && Array[low] <= pivot) {
      ++low;
    }
    // 5.将其移动到右边，与pivot换位置
    Array[high] = Array[low];
  }  // 不断重复这个过程，直到low和high相遇
  // 6.将pivot放置到相遇的位置，返回相遇的位置作为基准元素的最终位置
  Array[low] = pivot;
  return low;
}

void QuickSort(std::vector<int>& Array, int low, int high) {
  if (low >= high) return;
  int pivot = Paritition(Array, low, high);
  QuickSort(Array, low, pivot - 1);
  QuickSort(Array, pivot + 1, high);
}

void test12() {
  std::vector<int> Array = {2, 10, 5, 3, 6, 9, 1};
  for (auto a : Array) {
    std::cout << "a: " << a << " ";
  }
  std::cout << std::endl;

  QuickSort(Array, 0, Array.size() - 1);

  for (auto a : Array) {
    std::cout << "a: " << a << " ";
  }
  std::cout << std::endl;
}

int QuickSelect(std::vector<int>& Array, int low, int high, int target) {
  // 1.终止条件
  if (low == high) {
    return Array[low];
  }

  // 第K大元素的索引是N - K

  // 快排逻辑
  // 基准值左边的数都要更小，右边的数都要更大
  // 如果基准值索引更大，说明右边有超过N-K个元素比基准值小，虽然这些元素可能是乱序的，但第K大元素就在其中
  // 如果基准值索引更小，则相反

  // 2.返回基准值索引，其左边的元素都小于基准值，右边相反
  int pivotIndex = Paritition(Array, low, high);
  // 3.如果基准值索引等于数组个数 - K，即target，说明基准就是目标数
  // eg:  1, 2, 3, 4   找第2(K)大的数，那么就是3,刚好索引是数组个数 - K
  if (target == pivotIndex) return Array[pivotIndex];
  // 4.如果基准值索引更大，说明左边的
  else if (target < pivotIndex)
    return QuickSelect(Array, low, pivotIndex - 1, target);
  else
    return QuickSelect(Array, pivotIndex + 1, high, target);
}

void test13() {
  std::vector<int> Array = {2, 10, 5, 3, 6, 4, 1};
  int n = Array.size();
  int k = 2;
  int result = QuickSelect(Array, 0, n - 1, n - k);
  std::cout << "The " << k << "th largest element is: " << result << std::endl;
}

int main() {
  // test01();
  // test02();
  // test03();
  // test04();
  // test05();
  // test07();
  // test09();
  // test10();
  // test11();
  // test12();
  test13();

  system("read -p 'Press Enter to continue...' var");
}