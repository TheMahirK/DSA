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

void display(TreeNode *root)
{
    TreeNode *c = root;
    while (c != nullptr)
    {
        cout << c->data << ' ';
        c = c->right;
    }
    cout << endl;
}

void preOrder(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                cout << curr->data << ' ';
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

/*
Intuition : Use reverse post order traversal that is Right, Left, Root
Keep updating updating prev pointer and making right connection to prev pointer and left pointer to null

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
void flatten(TreeNode *root, TreeNode *&prev)
{
    if (root == nullptr)
    {
        return;
    }
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void flattenBinaryTree1(TreeNode *root)
{
    TreeNode *node = root;
    TreeNode *prev = nullptr;
    flatten(node, prev);
}

/*
Intuition : Use a manually created stack to simulate the above function iteratively
Store left node on top , connect left node to right side of tree
Repeat this for all sub trees

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/
void flattenBinaryTree2(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *currNode = st.top();
        st.pop();

        if (currNode->right)
        {
            st.push(currNode->right);
        }
        if (currNode->left)
        {
            st.push(currNode->left);
        }

        if (!st.empty())
        {
            currNode->right = st.top();
        }
        currNode->left = nullptr;
    }
}

void flattenBinaryTree3(TreeNode *root)
{
    TreeNode *currNode = root;
    while (currNode != nullptr)
    {
        if (currNode->left != nullptr)
        {
            TreeNode *prev = currNode->left;

            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = currNode->right;
            currNode->right = currNode->left;
            currNode->left = nullptr;
        }
        currNode = currNode->right;
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

    preOrder(root);

    flattenBinaryTree3(root);

    display(root);

    return 0;
}