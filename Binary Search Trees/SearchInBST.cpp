/*
Problem Name : Search in a Binary Search Tree
Problem Description : Given the root of a BST, and an integer value key, search the node with
value == key in BST and return its address, return nullptr if not found
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

Node *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    Node *root = new Node(data[i++]);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            Node *leftNode = new Node(data[i]);
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
            Node *rightNode = new Node(data[i]);
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
*/
Node *search(Node *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    int key = 13;

    Node *keyNode = search(root, key);

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
