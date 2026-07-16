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
Intuition : Height of tree with 1 node (root node) is 1
we can use recurrence relation maxHeight = 1 + maxHeight(left tree , right tree)
*/

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

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int maxHeight = getMaxHeight(root);
    cout << "Maximum height/depth of the tree : " << maxHeight;

    return 0;
}