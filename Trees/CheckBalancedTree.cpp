/*
Problem Name : Check Balanced Tree
Problem Description : Given root of a binary tree , return true if the tree is a balanced
binary tree

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of
every node never differs by more than one.

In other words for ALL NODES if abs(left height - right height) <= 1, the tree is
considered as a balanced binary tree
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

int getMaxHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

/*
Intuition : Use max height function to get height of tree at each node, if it does not satisfy
the balanced tree condition at any poin, return false , otherwise check for left half and then right half

Time Complexity : O(N^2)
N for getting height at each node , N for checking left and right halves at each node

Aux. Space Req. : O(height)

*/

bool isBalanced1(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }
    bool isLeftBalanced = isBalanced1(root->left);
    bool isRightBalanced = isBalanced1(root->right);

    if (!isLeftBalanced || !isRightBalanced)
    {
        return false;
    }
    return true;
}

int modifiedGetMaxHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);
}

/*
Intuition : This is an improved algorithm of prevous soln, instead of recursively checking for balanced
tree condition for each half by getting height of each half
we modify the height function to itself check for the balanced binary tree condition

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
bool isBalanced2(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int height = modifiedGetMaxHeight(root);
    if (height == -1)
    {
        return false;
    }
    return true;
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
    // TreeNode *seven = root->right->right;
    // seven->right = new TreeNode(8);
    // seven->right->left = new TreeNode(9);

    bool balanced = isBalanced2(root);

    if (balanced)
    {
        cout << "Tree is a balanced binary tree";
    }
    else
    {
        cout << "Tree is NOT a balanced binary tree";
    }

    return 0;
}