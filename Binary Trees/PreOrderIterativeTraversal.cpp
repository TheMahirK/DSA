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
Intuition : 
*/

void traversePreOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        cout << root->data << ' ';
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
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

    cout << "Preorder  : "; // 1 2 4 5 3 6 7
    traversePreOrder(root);
    cout << endl;

    return 0;
}