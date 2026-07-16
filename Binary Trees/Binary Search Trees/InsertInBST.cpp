/*
Problem Name : Insert a node in BST
Problem Description : Given the root of a BST and an integer value key , insert a new node in BST
with value = key such that the resultant tree is also a BST
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

// This for building large trees automatically using vector
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
// Just for output and debugging
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *currRoot = q.front();
            q.pop();

            if (currRoot->left)
            {
                q.push(currRoot->left);
            }
            if (currRoot->right)
            {
                q.push(currRoot->right);
            }
            cout << currRoot->data << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/*
Intuition : If the tree is already a valid BST and all node values are unique, the new node can be easily
inserted at its appropriate leaf node position

Use binary search to find its valid parent position , insert the node to its left or right as per value
This algorithm is simple and intuitive to implement but it inserts the node below last level
this increases the height of the tree

Time Complexity : O(logN)
Aux. Space Req. : O(1)

*/
TreeNode *insertInBST(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    TreeNode *curr = root;

    while (true)
    {
        if (value >= curr->data)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new TreeNode(value);
                break;
            }
        }

        else
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new TreeNode(value);
                break;
            }
        }
    }
    return root;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    cout << "Tree before insertion : " << endl;
    levelOrderTraversal(root);

    int key = 17;
    cout << "Tree after insertion : " << endl;
    root = insertInBST(root, key);

    levelOrderTraversal(root);

    return 0;
}
