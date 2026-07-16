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
Algorithm Used : Depth first search (DFS)
Time Complexity : O(N)
Aux. Space Req. : O(log N )
*/

// 1. Left subtree
// 2. Root node
// 3. Right subtree
void traverseInorder(TreeNode *root)
{
    if (root != nullptr)
    {
        traverseInorder(root->left);
        cout << root->data << ' ';
        traverseInorder(root->right);
    }
}

// 1. Root node
// 2. Left subtree
// 3. Right subtree

void traversePreorder(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';
        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

// 1. Left subtree
// 2. Right subtree
// 3. Root node

void traversePostorder(TreeNode *root)
{
    if (root != nullptr)
    {
        traversePostorder(root->left);
        traversePostorder(root->right);
        cout << root->data << ' ';
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

    cout << "Inorder   : "; // 4 2 5 1 6 3 7
    traverseInorder(root);
    cout << endl;

    cout << "Preorder  : "; // 1 2 4 5 3 6 7
    traversePreorder(root);
    cout << endl;

    cout << "Postorder : "; // 4 5 2 6 7 3 1
    traversePostorder(root);
    cout << endl;

    return 0;
}