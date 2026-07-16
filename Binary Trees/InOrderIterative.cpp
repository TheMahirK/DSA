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
Intuition : Simulate the recursive stack using manually created stack
*/

void traverseInOrder(TreeNode *root)
{
    // Left , Root, Right
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;

    TreeNode *node = root;

    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            cout << node->data << ' ';
            node = node->right;
        }
    }
    cout << endl;
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

    cout << "Inorder  : "; // 4 2 5 1 6 3 7
    traverseInOrder(root);
    cout << endl;

    return 0;
}