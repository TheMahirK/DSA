/*
Problem Name : Find Ceil value in a BST
Problem Description : Given the root of a BST and an integer value key , find the ceil of key value in
BST , if ceil does not exist , return -1

A ceil value of any key is the smallest value >= key value
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
Intuition : Use binary search in BST, if at any node , node->value == key , node->value is the ceil
If Key value > node value , search for bigger value (ceil) in right subtree
Else mark curr node value as ceil and try to find smallest value >= key value in left subtree

Time Complexity : O(logN)
Aux. Space Req. : O(1)
*/
int findCeil(Node *root, int key)
{
    int ceil = -1;
    while (root != nullptr)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    int key = 19;

    int ceil = findCeil(root, key);

    if (ceil != -1)
    {
        cout << "Ceil value for key " << key << " in BST is : " << ceil;
    }
    else
    {
        cout << "Ceil value for key " << key << " does NOT exist in BST";
    }

    return 0;
}
