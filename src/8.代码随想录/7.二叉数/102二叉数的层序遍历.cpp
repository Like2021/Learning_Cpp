#include<iostream>
#include<vector>

struct TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void order(TreeNode* cur, std::vector<std::vector<int>>& result, int depth)
{
    // 如果遍历到空，说明前面的节点就是底层节点
    if (cur == nullptr) return;
    
    if (result.size() == depth) result.push_back(std::vector<int> ());

}

void test01()
{

}

int main()
{
    test01();

    system("read -p 'Press Enter to continue...' var");
}