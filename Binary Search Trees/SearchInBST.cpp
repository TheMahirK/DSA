/*
Problem Name : Search in a Binary Search Tree
Problem Description : Given the root of a BST, and an integer value key, search the node with
value == key in BST and return its address, return nullptr if not found
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
Intuition : Take advantage of searching in BST like binary search by process of eliminations
as a valid BST has
all left node values < root node value < all right node values
for all sub trees

Time Complexity : O(log N)
Aux. Space Req. : O(log N)
*/
TreeNode *search1(TreeNode *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search1(root->left, key);
    }
    else
    {
        return search1(root->right, key);
    }
}

/*
Intuition : Take advantage of searching in BST like binary search by process of eliminations
as a valid BST has
all left node values < root node value < all right node values
for all sub trees

do an iterative binary search traversal to find the node

Time Complexity : O(log N)
Aux. Space Req. : O(1)
*/
TreeNode *search2(TreeNode *root, int key)
{
    TreeNode *curr = root;
    while (curr != nullptr && curr->data != key)
    {
        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return curr;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int key = 12;

    TreeNode *keyNode = search2(root, key);

    if (keyNode)
    {
        cout << "Key node with value " << key << " found at address : " << keyNode;
    }
    else
    {
        cout << "Key node with value " << key << " NOT found";
    }

    return 0;
}
