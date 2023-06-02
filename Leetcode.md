# 1. 数组

## 1. 二分查找

### 704. 二分查找

**题目：**

给定一个 `n` 个元素有序的（升序）整型数组 `nums`和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;  // 右边界初始化
        int left = 0;  // 左边界初始化

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target)  // 目标值在右半边
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)  // 目标值在左半边
            {
                right = mid - 1;  // 如果是左闭右开，这里就不用-1
            }
            else  // 找到目标值
            {
                return mid;
            }
        }
        
        return -1;  // 未找到目标值
    }
};
```





### 34. 在排序数组中查找元素的第一个和最后一个位置

**题目：**

给你一个按照非递减顺序排列的整数数组 `nums`，和一个目标值`target`。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 `target`，返回 `[-1, -1]`。

你必须设计并实现时间复杂度为 `O(log n)` 的算法解决此问题。



参考链接：[link](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/ru-he-ba-yi-dao-er-fen-fa-gei-mian-shi-g-yzcc/)

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchLeftOrRightBound(nums, target, "left"), searchLeftOrRightBound(nums, target, "right")};
    }
private:
    int searchLeftOrRightBound(vector<int>& nums, int target, const string& bound)
    {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target)  // target在右边的区间里，且肯定不是mid索引的元素，所以+1操作
            {
                left = mid + 1;  // [left, right] --> [mid + 1, right]
            }
            else if (nums[mid] > target)  // target在左边的区间里，且肯定不是mid索引的元素，所以-1操作
            {
                right = mid - 1;  // [left, right] -->[left, mid - 1]
            }
            else  // 第三种情况  nums[mid] == target
            {
                res = mid;  // 记录一下mid
                if (bound == "left")  // 如果是找做target第一个元素，则nums[mid] == target的情况下，第一个元素如果不是mid，那肯定在左边
                {
                    right = mid -1;  // 所以这里就更新一下右区间
                }
                else if (bound == "right")  // 如果是找做target最后一个元素，则nums[mid] == target的情况下，最后一个元素如果不是mid，那肯定在右边
                {
                    left = mid + 1;  // 所以这里就更新一下左区间
                }
                else
                {
                    // 异常处理段
                    cout << "传入正确边界参数" << endl;
                    break;
                }
            }
        }

        return res;
    }
};
```



### 69. x 的平方根 



给你一个非负整数 `x `，计算并返回 `x `的 算术平方根 。

由于返回类型是整数，结果只保留 **整数部分** ，小数部分将被 **舍去** 。

注意：不允许使用任何内置指数函数和算符，例如 `pow(x, 0.5)` 或者 `x ** 0.5` 。



参考链接：[link](https://leetcode.cn/problems/sqrtx/solution/x-de-ping-fang-gen-by-s1amduncan-74hw/)

```c++
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int result = 0;
        
        // 1. mid的平方小于x，那么有可能就是result，也有可能不是；
        // 2. mid的平方大于x，那么肯定不是result，就继续往小的猜，令right = mid - 1；
		// 3. mid的平方刚好等于x，那么再经过边界更新就不满足left <= right了。
        while (left 那么可不可以 以一种统一的逻辑来移除 链表的节<= right)
        {
            int mid = left + ((right - left) / 2);
            if ((long)mid * mid <= x)  // 强转成long类型，因为这里可能会超出int的范围
            {
                result = mid;  // 直接给result赋值,然后如果后续还能进行二分，即left <= right，就继续更新
                left = mid + 1;  // 所需的数在有半边
            }
            else  // 所需要的数在左半边
            {
                right = mid - 1;
            }
        }

        return result;  // 返回结果
    }
};
```





## 2. 移除元素

### 27. 移除元素

双指针思路：[link](https://www.bilibili.com/video/BV12A4y1Z7LP/?vd_source=ff498e5dc05e7bbe6be82c1d9e17f9fa)

快指针用来寻找新数组所需的元素，即除了需要删除的元素之外的所有元素；

慢指针用来记录新数组所需的元素。

![27.移除元素-双指针法](Leetcode/27.移除元素-双指针法.gif)

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        int size = nums.size();
        for (int fastIndex = 0; fastIndex < size; fastIndex++)
        {
            if (nums[fastIndex] != val)  // 寻找并不需要删除的元素
            {
                nums[slowIndex] = nums[fastIndex];  // 记录不需要删除的元素
                slowIndex++;  // 慢指针后移一位
            }
        }
        return slowIndex;  // 最后返回的slowIndex就是新数组的长度
    }
};
```



### 26. 删除有序数组中的重复项

参考链接：[link](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/solution/shuang-zhi-zhen-shan-chu-zhong-fu-xiang-dai-you-hu/)

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        int size = nums.size();

        if (size == 0) return 0;  // 判断nums是否为空
        
        // 1.如果快慢指针索引的元素相等，则快指针向后移一位，即fastIndex++操作
        // 2.如果快慢指针索引的元素不相等，则在慢指针后一位记录快指针索引的元素，即nums[++slowIndex] == nums[fastIndex]

        for (int fastIndex = 1; fastIndex < size; fastIndex++)  // 快指针初始化为1
        {
            if (nums[slowIndex] != nums[fastIndex])  // 找到非重复项
            {
                nums[++slowIndex] = nums[fastIndex];  // 在slowIndex + 1处 记录fastIndex索引的元素
            }
        }

        return slowIndex + 1  // 这里不好理解，可以举个极端的例子，例如nums是全为1的vector，最后删除重复项之后就只剩1个元素，没有非重复项，slowIndex就是0,所以要+1
    }
};
```



### 283. 移动零

参考链接：[link](https://leetcode.cn/problems/move-zeroes/solution/dong-hua-yan-shi-283yi-dong-ling-by-wang_ni_ma/)

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0, size = nums.size();
        if (size == 0)  // 判断是否为空
        {
            return;
        }

        for (int fastIndex = 0; fastIndex < size; fastIndex++)
        {
            if (nums[fastIndex] != 0)  // 寻找不等于0的元素
            {
                // 1.先用slowIndex去记录不等于0的元素
                // 2.slowIndex++
                nums[slowIndex++] = nums[fastIndex];
            }

            // 如果找到等于0的元素，只进行fastIndex++
        }

        for (; slowIndex < size; slowIndex++)  // 对于slowIndex后面的元素都赋值为0
        {
            nums[slowIndex] = 0;
        }
    }
};
```



## 3. 有序数组的平方

### 977. 有序数组的平方

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;  // 数组的索引，为长度-1
        // int k = nums.size();  // 也可以写成这样
        vector<int> result(nums.size(), 0);  // 创建个等长的全为0的新数组
        // vector<int> result(k, 0);

        // 比较nums[i] * nums[i]和nums[j] * nums[j]大小，哪个大就记录哪个
        // 然后把记录的那个元素的索引进行更新（i++或者j--），还有result的索引也更新（k--）
        for(int i = 0, j = k; i <= j;)
        // for (int i = 0, j = k - 1; i <= j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                // 1.j索引的数平方之后更大，就记录它并更新j
                result[k--] = nums[j] * nums[j];  // 先对result[k]进行赋值，然后k--
                // result[--k] = nums[j] * nums[j];  // 先更新k（--k），然后赋值
                j--;
            }
            else
            {
                // 2.i索引的数平方之后更大
                result[k--] = nums[i] * nums[i];
                // result[--k] = nums[i] * nums[i];  // 先更新k（--k），然后赋值
                i++;
            }
        }
        
        return result;
    }
};
```



## 4. 长度最小的子数组

### 209. 长度最小的子数组

**暴力解法：**

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;

        int result = INT32_MAX;  // 初始化result为最大值
        for (int i = 0; i < size; i++)
        {
            int sum = 0;  // 子序列之和
            int subLength = 0;  // 子数组的长度
            for (int j = i; j < size; j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    subLength = j - i + 1;  // 计算子数组的长度
                    result = result < subLength ? result : subLength;
                    break;  // 当前i符合条件的最短子数组已经找到了，跳出内层for循环
                }
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};
```

暴力解法是可以完成这个操作的，但力扣上提交会超时。



**移动窗口**

思路：

1. 先找到满足子序列之和大于等于目标值
2. 再从起始位置缩小子序列

![209.长度最小的子数组](Leetcode/209.长度最小的子数组.gif)

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int result = INT_MAX;
        int subSum = 0;
        int subLength = 0;

        int slowPoint = 0;  // 定义一个慢指针
        int fastPoint = 0;  // 定义一个快指针

        for (; fastPoint < size; fastPoint++)
        {
            subSum += nums[fastPoint];
            // 根据当前子序列的和大小，不断调节子序列的起始位置
            while (subSum >= target)
            {
                subLength = fastPoint - slowPoint + 1;
                result = result < subLength ? result : subLength;

                // 利用慢指针让连续的子序列从头开始减少一位（-=）
                // 然后对慢指针进行后移（slowPoint++）

                // 一旦子序列减少到subSum小于target，即题目条件不满足时，就停止
                subSum -= nums[slowPoint++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
```



## 5. 螺旋矩阵II

### 59.螺旋矩阵II

给你一个正整数 `n` ，生成一个包含 `1`到 `n^2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix` 。

示例1：

![spiraln](Leetcode/spiraln.jpg)

**解题思路：**

1. 填充上边
2. 填充右边
3. 填充下边
4. 填充左边

每次填充都是按顺序的左闭右开

左闭右开的判断，可以参考这个图，尤其是理解下边和左边遍历的时候：

![20220922102236](Leetcode/20220922102236.png)

#### 解决方法

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));  // 初始化一个二维数组
        int startX = 0, startY = 0;  // 定义每次循环一圈的起始位置，最开始是(0, 0)
        int mid = n / 2;  // 定义矩阵的中间索引，例如n = 3，则中间元素索引就是(1, 1)
        int loop = n / 2;  // 定义需要循环的圈数，配合if (n % 2)来判断n是否是奇数，即是否需要填最中间的值
        int count = 1;  // 定义一个初始化为1的元素，用来往数组插值，大小就是1～n^2
        int offset = 1;  // 定义一个用来控制每条边（循环一圈需要填4条边）遍历长度的变量，每循环一圈之后就+1
        int i, j;

        while (loop --)  // loop即循环次数，每循环一次就进行-1操作
        {
            // 先给循环使用的变量i, j赋值
            i = startX, j = startY;

            // 模拟示例1中的 循环填充元素
            // for循环不变量均设置成左闭右开
            
            // 1.遍历上边
            for (; j < n - offset; j++)  // n - offset 就是上边需要遍历的次数，例如，n = 5，第一圈就遍历4次， 第二圈就需要遍历3次
            {
                // 横坐标是不变的，都是startX
                result[startX][j] = count++;  // 再赋值之后，对count进行+1操作
            }

            // 2.遍历右边
            for (; i < n - offset; i++)  // 同样的，n - offset 就是右边需要遍历的次数
            {
                // 纵坐标是不变的，都是j，即经过上边遍历之后的j，例如n = 3时，上边遍历之后就变成j = 2了
                result[i][j] = count++;  // 一样赋值之后，再+1
            }

            // 3.遍历下边
            for (; j > startY; j--)  // j为变量，经过之前的for循环，已经变成了n - offset
            // 例如：循环第一圈的(startX, startY)为(0, 0)，那么j > startY，即从n - offset 到 0，左闭右开
            {
                result[i][j] = count++;
            }

            // 4.遍历左边
            for (; i > startX; i--)  // i为变量，经过之前的for循环，已经变成n - offset
            {
                result[i][startY] = count++;  // 其实这里的startY和j是一样的，遍历上边中的startX和i也是一样的
            }

            // 遍历完一圈之后，更新一些记录变量
            // 首先，更新起始位置
            startX++;
            startY++;

            // 其次，更新控制遍历长度的变量
            offset++;
        }

        // 循环完外边之后，如果n是奇数，那么就还需要添加最后一个数到最中间
        if (n % 2)  // 判断n是否是奇数，如果n除于2有余，那么就是奇数，执行添加
        {
            result[mid][mid] = count;  // count经过前面的while循环，已经是n^2了
        }


        // 返回这个矩阵
        return result;
    }
};
```



### 54. 螺旋矩阵

给你一个 `m` 行 `n` 列的矩阵 `matrix` ，请按照顺时针螺旋顺序 ，返回矩阵中的所有元素。



参考链接：[link](https://leetcode.cn/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/)

**解题思路：**

1. 首先定义上下左右边界，for循环采用左闭右闭
2. 先向右移动遍历到最右边，此时第一行已经遍历过了，可以将其在矩阵中删去，想象成m行变成m-1行，体现在代码里就是更新上边界
3. 判断在重新定义上边界之后，上下边界是否交错（因为边界采取的是左闭右闭，所以可以相等），如果交错，则遍历结束，跳出while循环
4. 如果不交错，则遍历还未结束，接下来依次：向下、向左、向上，完成遍历，步骤类似与第2步和第3步
5. 不断while循环，直到有两条边界交错，就break掉

#### 解决方法

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;  // 初始化一个返回容器
        if (matrix.empty()) return result;  // 如果为空直接返回初始化容器

        // 定义边界变量
        int leftBoundary = 0;
        int rightBoundary = matrix[0].size() - 1;  // 右边界即列数-1,因为下面for循环用的是<=，即左闭右闭
        int upperBoundary = 0;
        int lowerBoundary = matrix.size() - 1;  // 下边界即行数-1

        // 开始循环返回
        while (true)
        {
            for (int i = leftBoundary; i <= rightBoundary; i++)  // 向右移动，依次遍历
            {
                result.push_back(matrix[upperBoundary][i]);
            }
            if (++upperBoundary > lowerBoundary) break;  // 重新定义了上边界，若上边界大于下边界，则遍历完成，下同

            for (int i = upperBoundary; i <= lowerBoundary; i++)  // 向下移动，以此遍历
            {
                result.push_back(matrix[i][rightBoundary]);
            }
            if (--rightBoundary < leftBoundary) break;  // 重新定义右边界，进行减1，如果右边界小于左边界，则break

            for (int i = rightBoundary; i >= leftBoundary; i--)  // 向左移动
            {
                result.push_back(matrix[lowerBoundary][i]);
            }
            if (--lowerBoundary < upperBoundary) break;  // 重新定义下边界，进行减1,如果小于上边界，则break

            for (int i = lowerBoundary; i >= upperBoundary; i--)
            {
                result.push_back(matrix[i][leftBoundary]);  // 向上移动
            }
            if (++leftBoundary > rightBoundary) break;  // 重新定义左边界，进行+1,如果大于有边界，则break
        }

        return result;

    }
};
```



# 2. 链表

## 1. 移除链表元素

### 203. 移除链表元素

**题目：**

给你一个链表的头节点` head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val `的节点，并返回 新的头节点 。



1. 在没有虚拟头节点的链表里删除满足条件的节点

因为节点删除需要找到其前一个节点，故分为两种情况

a. 需要删除的是头节点

b. 需要删除的是非头节点

2. 设置虚拟头节点，统一删除

#### 解决方法1

参考链接：[link](https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头节点
        while (head != NULL && head->val == val)
        {
            ListNode* pDel = head;  // 缓存要删除的节点
            head = head->next;  // 将头节点新设置成下一个节点
            delete pDel;  // 删除原来的头节点
        }

        // 删除非头节点
        // 定义一个辅助指针变量
        ListNode* pCurrent = head;
        while (pCurrent != NULL && pCurrent->next != NULL)  // 一直遍历到最后一个节点
        {
            // 找到需要删除的节点的前一个节点
            if (pCurrent->next->val == val)
            {
                ListNode* pDel = pCurrent->next;
                pCurrent->next = pCurrent->next->next;  // 直接让前一个节点跳过需要删除的节点，指向下一个节点
                delete pDel;  // 释放内存
            }
            else
            {
                // 如果不是需要删除的节点，那么就让辅助指针变量后移
                pCurrent = pCurrent->next;
            }
        }

        // 返回头节点
        return head;
    }
};
```



#### 解决方法2

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 设置一个虚拟头节点
        ListNode* dummyHead = new ListNode(0);  // 设置一个虚拟头节点
        // 将虚拟头节点的next指向真实头节点
        dummyHead->next = head;

        // 定义一个辅助指针，让他指向虚拟头节点
        ListNode* pCurrent = dummyHead;

        while (pCurrent->next != NULL)  // 辅助指针从虚拟头节点开始，一直到最后一个节点，循环
        {
            if (pCurrent->next->val == val)
            {
                ListNode* pDel = pCurrent->next;
                pCurrent->next = pCurrent->next->next;
                delete pDel;
            }
            else
            {
                pCurrent = pCurrent->next;  // 非所需删除的节点，辅助指针向后移动
            }
        }

        head = dummyHead->next;  // 将新列表的头节点进行赋值
        delete dummyHead;  // 释放内存
        return head;  // 返回结果
    }
};
```



## 2. 设计链表

### 707.设计链表

参考链接：[link](https://leetcode.cn/problems/design-linked-list/solution/by-linken_54-7moa/)



## 3. 翻转链表 

### 206. 反转链表

![206.1](Leetcode/206.1.png)

#### 双指针法

![206.翻转链表](Leetcode/206.翻转链表.gif)

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pCurrent = head;  // 定义一个快指针  初始化为头节点
        ListNode* pNull = NULL;  // 定义一个慢指针  初始化为NULL

        while (pCurrent != NULL)
        {
            // 1.保存好当前pCurrent->next指向的节点，因为重新给pCurrent->next指向之后，就没办法利用pCurrent->next找到这个节点了
            ListNode* pTemp = pCurrent->next;

            // 2.重新给pCurrent->next指向  指向NULL
            pCurrent->next = pNull;

            // 3.重新给pCurrent 和 pNull赋值
            pNull = pCurrent;  // 慢指针当前的节点
            pCurrent = pTemp;  // 快指针指向保存好的下一个节点
        }
        // 最后pCurrent指向原来的尾部NULL，pNull指向反转后的头节点
        return pNull;
    }
};
```



#### 虚拟头节点法

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode();
        
        // 遍历所有节点
        ListNode* pCurrent = head;

        while (pCurrent != NULL)
        {
            // 记录pCurrent的下一个节点
            ListNode* pTemp = pCurrent->next;

            // 头插法
            pCurrent->next = dummyHead->next;  // 将原本的头节点的next指向null
            dummyHead->next = pCurrent;  // 将dummyHead的next指向原本的头节点
            pCurrent = pTemp;  // 更新辅助指针，为下一个节点
        }

        return dummyHead->next;  // 返回虚拟头节点的下一个节点，也就是新头节点
    }
};
```



## 4. 两两交换链表中的节点

### 24. 两两交换链表中的节点

**题目：**

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

**解题参考：**

[代码随想录](https://www.programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#_24-%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9)



```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 设置虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        // 将虚拟头节点的next赋为头节点
        dummyHead->next = head;
        // 创建临时指针
        ListNode* pCurrent = dummyHead;
        while (pCurrent->next != nullptr && pCurrent->next->next != nullptr)
        {
            // 保存原本的第一个节点
            ListNode* pTemp = pCurrent->next;
            // 保存原本的第三个节点
            ListNode* pTemp1 = pCurrent->next->next->next;

            // 1.将虚拟头节点的下一个节点指向原本的的第二个节点
            pCurrent->next = pCurrent->next->next;
            // 2.将上一步指向的节点的下一个节点指向原本的第一个节点
            // 这样就完成了原本的第一个和第二个节点的互换
            pCurrent->next->next = pTemp;
            // 3.将完成互换之后的第二个节点的next指向原本的第三个节点
            pCurrent->next->next->next = pTemp1;

            // 完成后 更新pCurrent
            // 向后移动两位
            pCurrent = pCurrent->next->next;
        }
        return dummyHead->next;
    }
};
```



## 5. 删除链表的倒数第N个节点

### 19. 删除链表的倒数第N个节点

**题目：**

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

**解题思路：**

参考链接：[代码随想录](https://www.programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html#_19-%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACn%E4%B8%AA%E8%8A%82%E7%82%B9)

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 创建快慢指针
        ListNode* pSlow = dummyHead;
        ListNode* pFast = dummyHead;

        // 1 先让快指针移动n步
        while (n-- && pFast != nullptr)
        {
            pFast = pFast->next;
        }

        // 2 细节的地方 让快指针再往前走一步，
        // 这样同时移动快慢指针的时候，慢指针就可以指向需要删除节点的前一个节点
        pFast = pFast->next;

        // 3 同时移动快慢指针
        while (pFast != nullptr)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        // 4 删除慢指针指向的下一个节点
        // 原理就是让慢指针的next 直接指向下两个节点
        pSlow->next = pSlow->next->next;

        return dummyHead->next;
    }
};
```



## 6. 链表相交

### 面试题 02.07 链表相交

**题目：**

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。



#### 解决方法1

**解题思路：**



```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 创建辅助指针
        ListNode* curA = headA;
        ListNode* curB = headB;

        // 计算链表长度
        int lenA = 0, lenB = 0;
        while (curA != NULL)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL)
        {
            lenB++;
            curB = curB->next;
        }

        // 让辅助指针重新指向两个链表的头节点
        curA = headA;
        curB = headB;

        // 保证curA指向最长链表
        if (lenB > lenA)  // 如果不是，就交换
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 求出长度差
        int gap = lenA - lenB;

        // 让curA先遍历gap
        while (gap--)
        {
            curA = curA->next;
        }
        // 再一起遍历curA和curB
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            // 更新curA 和 curB
            curA = curA->next;
            curB = curB->next;
        }

        // 遍历完都没有找到，则返回NULL
        return NULL;
    }
};
```



#### 解决方法2

**解题思路：**

参考链接：[LeetCode](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/solution/mian-shi-ti-0207-lian-biao-xiang-jiao-sh-b8hn/)



```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 创建辅助指针
        ListNode* A = headA;
        ListNode* B = headB;

        // 两个辅助指针同步遍历两个链表
        // 具体来说，A先遍历链表1，然后再从链表2的头节点开始遍历链表2
        // B也是这样

        // 当A = B时，走到公共节点
        while (A != B)
        {
            // 这里就是如果辅助指针遍历完了一个链表，就让其指向下一个链表的头节点
            A = A != NULL ? A->next : headB;
            B = B != NULL ? B->next : headA;

            // 特殊情况就是，两个链表没有交点
            // 辅助指针A和B最后都遍历完两个链表，都能等于null，循环结束
        }

        return A;
    }
};
```



## 7.环形链表II

### 142. 环形链表II

**题目：**

给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 `null`。*



**解题思路：**

1. 设置快慢指针，快指针移动两步，慢指针移动一步

![141.环形链表](Leetcode/141.环形链表.gif)

2. 找相遇节点，只要有环，快慢指针肯定会相遇，循环条件就是快指针移动到`null`或者它的下一个节点是`null`

![img](Leetcode/20220925103433.png)

3. 找到相遇节点，再利用两个辅助指针，定义相遇节点和头节点，同时移动一步，相等时就是环形入口

![142.环形链表II（求入口）](Leetcode/142.环形链表II（求入口）.gif)



参考链接中有公式推理：[代码随想录](https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF)



```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 1.定义快慢指针
        ListNode* pFast = head;
        ListNode* pSlow = head;

        // 2.找两个指针相遇的节点
        // 因为pFast每次移动两步，所以判断只要当前快指针是null或者它的下一个节点是null，就结束循环
        while (pFast != NULL && pFast->next != NULL)
        {
            // 慢指针移动一步
            pSlow = pSlow->next;
            // 快指针移动两步
            pFast = pFast->next->next;

            // 找到相遇节点
            if (pSlow == pFast)
            {
                // 定义辅助指针，记录相遇节点和头节点
                ListNode* pIdx1 = pFast;
                ListNode* pIdx2 = head;

                // 两个节点同时移动，相等时就是入口节点
                while (pIdx1 != pIdx2)
                {
                    pIdx1 = pIdx1->next;
                    pIdx2 = pIdx2->next;
                }

                return pIdx1;
            }
        }
        
        return NULL;
    }
};
```

# 3. 哈希表

[基本知识链接](https://programmercarl.com/%E5%93%88%E5%B8%8C%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E5%93%88%E5%B8%8C%E8%A1%A8)

## 1. 有效字母异位词

### 242. 有效的字母异位词

**题目：**

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



**解题思路：**

1. 初始化一个记录字符出现次数的数组（哈希表），size为26
2. 遍历第一个字符串，在字符相对`a`的位置处做`+1`操作，如下图
3. 再遍历第二个字符串，在字符相对`a`的位置处做`-1`操作，如下图
4. 最后再遍历数组，如果有非0数，则说明两个字符串不是异位数，反之则是异位数

![242.有效的字母异位词](Leetcode/242.有效的字母异位词.gif)

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 初始化一个记录字符出现次数的数组
        int record[26] = {0};

        // 遍历字符串s
        for (int i = 0; i < s.size(); i++)
        {
            // 并不需要具体记录字符的ASCII，只需要记录相对的值
            // 即 a代表0,b代表1....
            record[s[i] - 'a']++;
        }
        // 遍历字符串t
        for (int i = 0; i < t.size(); i++)
        {
            // 出现某个字符，就在它对应的位置记录-1
            record[t[i] - 'a']--;
        }
        // 遍历完后查看record情况
        // 均为0则返回true，是字母异位词
        for (int i = 0; i < sizeof(record) / sizeof(record[1]); i++)
        {
            // 如果出现有非0数，返回false
            if (record[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
```

### 383. 赎金信

**题目：**

给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

`magazine` 中的每个字符只能在 `ransomNote` 中使用一次。

**解题思路：**

和242题类似，但判断情况有些不同

当遍历第二个字符串的时候，做`-1`操作之后，**判断一下当前操作的数组位置记录的是否小于0**，如果小于0，则返回`false`

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 初始化一个记录字符出现次数的数组
        int record[26] = {0};

        // 遍历第一个字符串 magazine
        for (int i = 0; i < magazine.size(); i++)
        {
            // 记录字符出现的次数 做+1操作
            record[magazine[i] - 'a']++;
        }
        // 遍历第二个字符串 ransomNote
        for (int i = 0; i < ransomNote.size(); i++)
        {
            // 记录字符出现次数 做-1操作
            record[ransomNote[i] - 'a']--;
            // 一旦出现小于0,即ransomNote中有magazine中不曾出现或者出现次数不够的字符
            // 直接返回false
            if (record[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        
        return true;
    }
};
```

## 2. 两个数组的交集

### 349. 两个数组的交集

**题目：**

给定两个数组，编写一个函数来计算它们的交集。

说明： 输出结果中的每个元素一定是唯一的。 我们可以不考虑输出结果的顺序。



#### 解题方法1

利用一种哈希数据结构：`unordered_set`

![set哈希法](Leetcode/20220707173513.png)

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 创建一个存放结果的unordered_set
        unordered_set<int> result_set;
        // 拷贝一份 nums1 到unordered_set，用于比较
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        // 遍历nums2
        for (int num : nums2)
        {
            // 如果发现num在nums_set中重复出现了，记录它
            if (nums_set.find(num) != nums_set.end())
            {
                // find()，如果没找到默认返回end()迭代器
                result_set.insert(num);
            }
        }

        // 最后返回结果，利用拷贝构造,返回vector
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```

#### 解题方法2

对于有确定数值范围的情况下，可以使用数组

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 存放结果，用这个容器是为了去重
        unordered_set<int> result_set;
        // 初始化一个数组，记录映射出现的次数
        int hash[1005] = {0};

        // 遍历第一个数组 赋值为1
        for (int num : nums1)
        {
            hash[num] = 1;  // 不考虑重复的情况
        }
        // 遍历第二个数组
        for (int num : nums2)
        {
            // 如果同时在nums1中出现
            if (hash[num] == 1)
            {
                result_set.insert(num);
            }
        }

        // 拷贝构造的方法 返回最后结果
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```



## 3. 快乐数

### 202. 快乐数

**题目：**

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为 1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

**示例：**

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

**解题思路：**

[代码随想录链接](https://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html)

**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。**

判断sum是否重复出现就可以使用unordered_set。

1. 写一个返回求和结果`sum`，计算每个位置平方和结果的函数
2. 利用这个函数返回的结果`sum`，判断是否是快乐数，或者是否进入死循环了
3. 具体就是，`sum == 1`就是快乐数，如果能在`unordered_set`里面找到，说明出现过了，进入死循环了，反之就记录这个数
4. 最后别忘了更新下一个循环的`n`

```c++
class Solution {
public:
    // 取各个位置的数值 做平方
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            // 先记录个位数
            sum += (n % 10) * (n % 10);
            // 再除于10，然后循环继续记录个位数
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        // 初始化一个set
        unordered_set<int> set;
        while (1)
        {
            // 做快乐数计算
            int sum = getSum(n);
            if (sum == 1)
            {
                // 如果sum==1，返回true
                return true;
            }

            // 如果sum出现过，则说明进入无限循环了，返回false
            if (set.find(sum) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(sum);
            }

            // 完成记录之后 更新n，进入下一个循环
            n = sum;
        }
    }
};
```



## 4. 两数之和

### 1. 两数之和

**题目：**

给定一个整数数组 `nums `和一个目标值 `target`，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

**解题思路：**

用数据元素去查询下标，所以 map中的存储结构为 {key：数据元素，value：数组元素对应的下标}。

1. 利用`unordered_map`来记录数组里面的数据元素和下标
2. 先遍历数组元素，然后去`unordered_map`中寻找另一个符合条件的数
3. 如果没找到，则把当前遍历出来的元素存放到`unordered_map`中，如果找到了，则返回遍历的索引和容器中对应的`value`

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            // 遍历数组元素，并在map中寻找匹配的数
            auto iter = map.find(target - nums[i]);
            // 如果找到map中有匹配的数
            if (iter != map.end())
            {
                // 返回value和i
                return {iter->second, i};
            }
            // 如果没找到，则把遍历出来的数组元素记录到map
            map.insert(pair<int, int>(nums[i], i));
        }

        // 最后如果都没找到的话，返回空
        return {};
    }
};
```



## 5. 四数相加II

### 454. 四数相加II

**题目：**

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

**解题思路：**

这道题目是四个独立的数组，只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，不用考虑有重复的四个元素相加等于0的情况

思路和两数之和的类似

1. 利用一个`unordered_map`记录前两个数组A和B遍历出来的元素a与b之和，以及之和出现的次数
2. 再去遍历数组C和D的元素c和d，判断`unorderen_map`中是否有`a + b`满足`a + b + c + d = 0`
3. 如果有，说明满足条件，且`a + b`对应的`value`就是满足条件出现的次数，用一个变量记录下来

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // key记录a+b的和，value记录a+b之和出现的次数
        unordered_map<int, int> uMap;
        // 遍历A和B，统计元素之和，和出现的次数
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                // +1操作
                uMap[a + b]++;
            }
        }

        // 初始化一个int变量记录满足条件的情况
        int count = 0;
        // 遍历C和D，去找0 - (c + d)是否在uMap中出现过
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                // 如果出现过，则记录uMap中a+b之和出现的次数，即为满足条件的次数
                if (uMap.find(0 - c - d) != uMap.end())
                {
                    count += uMap[0 - c - d];
                }
            }
        }

        // 最后返回结果
        return count;
    }
};
```

# 4. 字符串

## 1. 反转字符串

### 344. 反转字符串

**题目：**

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。



**解题思路：**

对于字符串，我们定义两个指针（也可以说是索引下标），一个从字符串前面，一个从字符串后面，两个指针同时向中间移动，并交换元素。

![344.反转字符串](Leetcode/344.反转字符串.gif)

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 两个指针 同时在头和尾开始往中间移动
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};
```

### 541. 反转字符串II

**题目：**

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 `2k `但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

**解题思路：**
