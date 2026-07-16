/*
Problem Name : Find the Kth smallest node in BST
Problem Description : Given the root of a BST , and an integer k , find the kth smalles node present in BST
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
Intuition : Use in order traversal to traverse elements in sorted order, decrement k for each node visited
when k becomes zero , we reach the kth smallest value node in BST

In a BST , the inorder traversal always traverses/gives values in sorted order
as in a BST, left values < root value < right values , and in order traversal traverses
left nodes , root nodes, right nodes

Time Complexity : O(logN)
Aux. Space Req. : O(height)
*/
void kthSmallest(TreeNode *root, int &k, int &ans)
{
    if (root == nullptr || ans != -1)
    {
        return;
    }
    kthSmallest(root->left, k, ans);
    if (--k == 0)
    {
        ans = root->data;
        return;
    }
    kthSmallest(root->right, k, ans);
}

int kthSmallestElement1(TreeNode *root, int k)
{
    int ans = -1, count = 0;
    kthSmallest(root, k, ans);
    return ans;
}

/*
Intuition : Do the same as above but using morris traversal to avoid aux. space req.

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/
void inOrder(TreeNode *root, int k, int &ans)
{
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            if (--k == 0)
            {
                ans = curr->data;
            }
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
                if (--k == 0)
                {
                    ans = curr->data;
                }
                curr = curr->right;
            }
        }
    }
}

int kthSmallestElement2(TreeNode *root, int k)
{
    int ans = -1;
    inOrder(root, k, ans);
    return ans;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int k = 15;

    int kthElement = kthSmallestElement2(root, k);

    if (kthElement != -1)
    {
        cout << k << "th smallest Element in BST : " << kthElement;
    }
    else
    {
        cout << k << "th smallest element does not exist, as k > N";
    }
    cout << endl;

    return 0;
}
