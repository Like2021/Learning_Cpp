#include<iostream>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 创建新的节点
TreeNode* newTreeNode(int val)
{
    // 申请一个TreeNode类型变量的地址空间
    TreeNode* node = new TreeNode;
    // 初始化节点
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 查找给定数据，并修改成新数据操作
void search(TreeNode* root, int x, int newData)
{
    if (root == NULL) return;
    if (root->val == x)
    {
        // 找到对应的数据，并进行修改
        root->val = newData;
    }
    search(root->left, x, newData);
    search(root->right, x, newData);
}

// 实现二叉数节点的插入
void insert(TreeNode*& root, int x)
{
    if (root == NULL)
    {
        root = newTreeNode(x);
        return;
    }
    
}