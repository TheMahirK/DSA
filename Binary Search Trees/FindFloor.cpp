/*
Problem Name : Find Floor value in a BST
Problem Description : Given the root of a BST and an integer value key , find the floor of key value in
BST , if ceil does not exist , return -1

A floor value of any key is the largest value <= key value
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
Intuition : Use binary search on BST ,
1. if node value == key , node value is the floor
2. If key > node value , curr node value can be possible answer , we store it and move right to find
maximum value <= key
3. If key < node value , we repeat above steps 1 and 2 in left sub tree

Time Complexity : O(logN)
Aux. Space Req. : O(1)
*/
int findFloor(TreeNode *root, int key)
{
    int floor = -1;
    while (root != nullptr)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }
        else if (key > root->data)
        {
            floor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int key = 13;

    int ceil = findFloor(root, key);

    if (ceil != -1)
    {
        cout << "Floor value for key " << key << " in BST is : " << ceil;
    }
    else
    {
        cout << "Floor value for key " << key << " does NOT exist in BST";
    }

    return 0;
}
