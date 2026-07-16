/*
Problem Name : Morris Traversal
Problem Description : Given the root of a binary tree Traverse tree in In order, pre order without using any extra space
that means Aux. Space Req. should be O(1)
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



TreeNode *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    TreeNode *root = new TreeNode(data[i++]);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(data[i]);
            currNode->left = leftNode;
            q.push(leftNode);
        }
        i++;
        if (data[i] == -1)
        {
            currNode->right = nullptr;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(data[i]);
            currNode->right = rightNode;
            q.push(rightNode);
        }
        i++;
    }
    return root;
}

/*
Intuition : Use thread connection concept to go back to root
Steps
1. Remember current node
2. Go to right most node of left sub tree
3. Connect right most node to current node
4. Traverse tree normally
5. When reached at right most node , go directly back to parent node via connection
6. Repeat the steps 1 to 5 for right side

This prints as Left, Root, Right

Time Complexity : ~ O(2N)
Aux. Space Req. : O(1)
*/

void inOrder(TreeNode *root)
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
                curr = curr->left;
            }

            else
            {
                prev->right = nullptr;
                cout << curr->data << ' ';
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

// Do the same as in order traversal above but change the print condition to print as Root, Left, Right
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

int main()
{
    vector<int> tree = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildTree(tree);

    cout << "Preorder traversal : ";
    preOrder(root);

    cout << "Inorder traversal : ";
    inOrder(root);

    return 0;
}