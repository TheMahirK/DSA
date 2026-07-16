/*
Problem Name : Check Identical Trees
Problem Descriptuon : Given roots of two trees
return true if both the trees are identical (in terms of values and their arrangements) otherwise
return false
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
Intuition : We can use any traversal (in order / pre order / post order) on both trees simultaneously
to check for equality of nodes and equality of their arrangement

Identical trees have same traversal , non identical trees do not have same traversal

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/

bool isIdentical(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return (root1 == root2);
    }
    return (root1->data == root2->data) && isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
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

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);

    bool isSame = isIdentical(root, root2);

    if (isSame)
    {
        cout << "Both the trees are identical to each other";
    }
    else
    {
        cout << "The trees are NOT identical to each other";
    }

    return 0;
}