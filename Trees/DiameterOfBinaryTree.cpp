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
Intuition : The diameter of a the tree is max. left height + max. right height
recursively find diameter for left tree and right tree. At every step keep checking for maximum diameter
Time Complexity : O(N^2)
Aux. Space Req. : O(height of tree)
*/

// This is a helper function for getTreeDiameter1
void getTreeDiameter(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    diameter = max(diameter, leftHeight + rightHeight);

    getTreeDiameter(root->left, diameter);
    getTreeDiameter(root->right, diameter);
}

int getTreeDiameter1(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int diameter = 0;
    getTreeDiameter(root, diameter);
    return diameter;
}

/*
Intuition : Height of tree with 1 node (root node) is 1
we can use recurrence relation maxHeight = 1 + maxHeight(left tree , right tree)
*/

int getMaxHeight(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getMaxHeight(root->left, diameter);
    int rightHeight = getMaxHeight(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

/*
Intuition : The diameter of a the tree is max. left height + max. right height
Use modify max height function to recursively find diameter of the tree
Time Complexity : O(N)
Aux. Space Req. : O(height of tree)
*/
int getTreeDiameter2(TreeNode *root)
{
    int diameter = 0;
    getMaxHeight(root, diameter);
    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    TreeNode *six = root->right->left;
    root->right->right = new TreeNode(7);
    TreeNode *seven = root->right->right;
    seven->right = new TreeNode(0);

    six->right = new TreeNode(9);
    six->right->right = new TreeNode(10);

    int diameter = getTreeDiameter2(root);

    cout << "The Diameter of the tree is : " << diameter;

    return 0;
}