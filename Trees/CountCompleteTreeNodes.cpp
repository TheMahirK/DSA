/*
Problem Name : Count total no. of nodes in a complete binary tree
Problem Description : Given the hea of a complete binary tree , find out the total no. of nodes in the
complete binary tree

A complete binary tree is a binary tree in which every level, except possibly the last, is completely
filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h
nodes at the last level h.[20] A perfect tree is therefore always complete
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

/*
Intuition : Traverse recursively in any order (pre, in , post)
Return +1 for every node traversed to get total no. of nodes

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
int countNodes1(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes1(root->left) + countNodes1(root->right);
}

int leftHeight(TreeNode *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}

int rightHeight(TreeNode *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}

/*
Intuition : Traverse recursively to count nodes but dont count all nodes , the number of nodes in a
fully complete binary tree = 2^height - 1
We take advantage of the definition of complete binary tree
which is all nodes are present in a level or all nodes are left concentrated in last level
which gives us idea that at some point full complete binary tree is going to be present somewhere in left
half of the tree from there we backtrack

Time Complexity : O((logN)^2)

logN for left/right height
logN for traversal , logN for worst case (full binary tree present) as return (1<<lh)-1 log N times

Aux. Space Req. : O(logN)
*/

int countNodes2(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
    {
        return (1 << lh) - 1;
    }
    return 1 + countNodes2(root->left) + countNodes2(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int nodes = countNodes2(root);

    cout << "Number of nodes in complete binary tree : " << nodes;

    return 0;
}
