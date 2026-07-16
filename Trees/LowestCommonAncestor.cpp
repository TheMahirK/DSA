/*
Problem Name : Find lowest/closest common ancestor
Problem Description : Given the root of a binary tree and two nodes p and q, find the lowest/closest
common ancestor in the tree

A lowest/closest common ancestor is the first intersection found when we traverse from both nodes from
bottom to top order
Note : A node itself can be its closest common ancestor
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
Intuition : Use concept
If node p exists below left/right side we say it exists
If node q exists below left/right side we say it exists

The node below which both the nodes exist is the closest/lowest ancestor
We can implement this using recursive traversal

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
TreeNode *getLowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }
    TreeNode *left = getLowestCommonAncestor(root->left, p, q);
    TreeNode *right = getLowestCommonAncestor(root->right, p, q);

    if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    else
    {
        return root;
    }
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

    TreeNode *node1 = root->left->left;
    TreeNode *five = root->left->right;
    TreeNode *node2 = new TreeNode(8);
    five->right = node2;

    TreeNode *closestAncestor = getLowestCommonAncestor(root, node1, node2);

    cout << "The closest ancestor of " << node1->data << " and " << node2->data << " : "
         << closestAncestor->data;

    return 0;
}