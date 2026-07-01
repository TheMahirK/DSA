/*
Problem Name : Boundary Traversal
Problem Description : Given the root of a binary tree , find the boundary traversal of the tree
A boundary traversal traverses all boundary nodes from left to right
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

bool isLeaf(Node *root)
{
    return (root->left == nullptr && root->right == nullptr);
}

void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *currNode = root->left;
    while (currNode != nullptr)
    {
        if (!isLeaf(currNode))
        {
            ans.push_back(currNode->data);
        }
        // Keep going downward in left direction
        if (currNode->left != nullptr)
        {
            currNode = currNode->left;
        }
        // if left doesnt exist , right node is part of boundary
        else
        {
            currNode = currNode->right;
        }
    }
}

void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *currNode = root->right;
    vector<int> temp;
    while (currNode != nullptr)
    {
        if (!isLeaf(currNode))
        {
            temp.push_back(currNode->data);
        }
        // Keep going down in right direction
        if (currNode->right != nullptr)
        {
            currNode = currNode->right;
        }
        // if right does not exist, left node is part of boundary
        else
        {
            currNode = currNode->left;
        }
    }

    // Insert in reverse order
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void addLeafNodes(Node *root, vector<int> &ans)
{
    // Add leaf nodes from left to right
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left != nullptr)
    {
        addLeafNodes(root->left, ans);
    }
    if (root->right != nullptr)
    {
        addLeafNodes(root->right, ans);
    }
}

/*
Intuition : Follow these steps
1. Add root if its not leaf node
2. Add all left boundary nodes excluding leaf nodes
3. Add all leaf nodes
4. Add all right boundary nodes from bottom to top (or reverse of top to bottom)
*/

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeftBoundary(root, ans);
    addLeafNodes(root, ans);
    addRightBoundary(root, ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Node *five = root->left->right;
    five->left = new Node(15);
    five->right = new Node(30);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *seven = root->right->right;
    seven->right = new Node(9);
    seven->left = new Node(8);

    vector<int> boundary = boundaryTraversal(root);
    display(boundary);

    return 0;
}