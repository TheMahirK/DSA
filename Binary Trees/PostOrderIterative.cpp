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
Intuition : Use two stacks , first to store the left most nodes , second to store the traversed nodes
*/

void traversePostOrder1(TreeNode *root)
{
    // Left , Right , Root
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    TreeNode *node = root;
    st1.push(node);

    while (!st1.empty())
    {
        node = st1.top(); // current left most node
        st1.pop();
        st2.push(node);

        if (node->left)
        {
            st1.push(node->left);
        }
        if (node->right)
        {
            st1.push(node->right);
        }
    }

    while (!st2.empty())
    {
        node = st2.top();
        st2.pop();
        cout << node->data << ' ';
    }
    cout << endl;
}

void traversePostOrder2(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            TreeNode *temp = st.top()->right;

            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << ' ';

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << ' ';
                }
            }
            else
            {
                curr = temp;
            }
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

    cout << "Post Order  : "; // 4 5 2 6 7 3 1
    traversePostOrder2(root);

    return 0;
}