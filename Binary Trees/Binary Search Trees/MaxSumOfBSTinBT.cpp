/*
Problem Name : Maximum Sum of a BST in a Binary Tree
Problem Description : Given the root of a binary tree , find the maximum sum of a Binary Search tree
present in the binary tree

Note : A tree with single node is a binary search tree
A tree with no node is also considered a binary search tree , with sum = 0
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data, TreeNode *left = nullptr, TreeNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

TreeNode *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    TreeNode *root = new TreeNode(data[i++]);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(data[i]);
            currNode->left = leftNode;
            q.push(leftNode);
        }
        i++;
        if (data[i] == -1)
        {
            currNode->right = nullptr;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(data[i]);
            currNode->right = rightNode;
            q.push(rightNode);
        }
        i++;
    }
    return root;
}

bool checkValidity(TreeNode *root, int leftRange, int rightRange)
{
    if (root == nullptr)
    {
        return true;
    }
    int value = root->data;
    if (value <= leftRange || value >= rightRange)
    {
        return false;
    }
    return checkValidity(root->left, leftRange, value) && checkValidity(root->right, value, rightRange);
}

bool validateBST(TreeNode *root)
{
    int leftRange = INT_MIN, rightRange = INT_MAX;
    return checkValidity(root, leftRange, rightRange);
}

int sum(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sum(root->left) +
           sum(root->right);
}

void maxSum(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return;
    }
    maxSum(root->left, ans);
    if (validateBST(root))
    {
        int currSum = sum(root);
        ans = max(currSum, ans);
    }
    maxSum(root->right, ans);
}

/*
Intuition : This is extreme brute force solution, check for BST validity of each subtree, if the subtree
is a valid BST , we find the sum of all nodes in that BST and update MaxSum

Time Complexity : O(N^2)
Aux. Space Req. : O(height)
*/
int getMaxSum1(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 0;

    maxSum(root, ans);
    return ans;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int maxS = getMaxSum1(root);

    cout << "Maximum sum of a BST in given Binary Tree : " << maxS;

    return 0;
}