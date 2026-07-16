/*
Problem Name : Validate a BST
Problem Description : Given the root of a binary tree , return true if the given binary tree is a BST
otherwise return false
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
Intuition : Use range parameter to check the validity , a tree is valid if curr node value is greater than lower limit and
less than upper limit, when we move left , the upper limit becomes curr node value. When we move right , the lower limit
becomes curr node value

If current node satisfies the validity condition , we verify for left half of the tree and right half of the tree with changed
lower and upper limits

Otherwise we return false, doing this recursively for whole tree and ANDing all the outputs we get output for the whole tree

Time Complexity : O(N)
Aux. Space Req. : O(logN)
*/
bool checkValidity(TreeNode *root, int leftRange, int rightRange)
{
    if (root == nullptr)
    {
        return true;
    }
    int value = root->data;
    if (value < leftRange || value > rightRange)
    {
        return false;
    }
    return checkValidity(root->left, leftRange, value) && checkValidity(root->right, value, rightRange);
}

bool validateBST(TreeNode *root)
{
    int leftRange = INT_MIN, rightRange = INT_MAX;
    return checkValidity(root, leftRange, rightRange);
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    bool isValid = validateBST(root);

    if (isValid)
    {
        cout << "Given Binary tree is a valid BST";
    }
    else
    {
        cout << "Given Binary tree is NOT a valid BST";
    }

    return 0;
}
