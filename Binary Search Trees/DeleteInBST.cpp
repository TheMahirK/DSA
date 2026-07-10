/*
Problem Name : Delete a node in BST
Problem Description : Given the root of a BST and an integer value key , delete the node within BST
with value = key such that the resultant tree is also a BST
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

// This for building large trees automatically using vector
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
// Just for output and debugging
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *currRoot = q.front();
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

Node *findRight(Node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

Node *helper(Node *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    if (root->right == nullptr)
    {
        return root->left;
    }

    Node *rightChild = root->right;
    Node *lastRight = findRight(root->left);
    lastRight->right = rightChild;
    Node *temp = root->left;
    delete root;
    return temp;
}

/*
Intuition : Use binary search to find the parent node of the target node , attach left side of target node to parent node
attach right side of target node to right most node of left sub tree
In this way the target node can be deleted while still maintaining the property of the BST

Time Complexity : O(logN)
Aux. Space Req. : O(1)

*/
Node *deleteNode1(Node *root, int value)
{
    if (root->data == value)
    {
        return helper(root);
    }

    Node *curr = root;

    while (curr != nullptr)
    {
        if (value < curr->data)
        {
            if (curr->left && curr->left->data == value)
            {
                curr->left = helper(curr->left);
                break;
            }
            else
            {
                curr = curr->left;
            }
        }

        else
        {
            if (curr->right && curr->right->data == value)
            {
                curr->right = helper(curr->right);
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    return root;
}

Node *findLeft(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *helper2(Node *root)
{
    if (root->left == nullptr)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    if (root->right == nullptr)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    Node *leftChild = root->left;
    Node *lastLeft = findLeft(root->right);
    lastLeft->left = leftChild;
    Node *temp = root->right;
    delete root;
    return temp;
}

/*
This is same algorithm , in this we do slight opposite of previous algorithm
In this we attach right side to parent node and left sub tree to left most part of the right sub tree

Time Complexity : O(logN)
Aux. Space Req. : O(1)
*/
Node *deleteNode2(Node *root, int value)
{
    if (root->data == value)
    {
        return helper2(root);
    }

    Node *curr = root;
    while (curr != nullptr)
    {
        if (value < curr->data)
        {
            if (curr->left && curr->left->data == value)
            {
                curr->left = helper2(curr->left);
                break;
            }
            else
            {
                curr = curr->left;
            }
        }

        else
        {
            if (curr->right && curr->right->data == value)
            {
                curr->right = helper2(curr->right);
                break;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    return root;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    // vector<int> tree = {10, 5, 12, 2, 8, 11, 14, -1, -1, -1, -1, -1, -1, -1, -1};

    Node *root = buildTree(tree);

    cout << "Tree before deletion : " << endl;
    levelOrderTraversal(root);

    int value = 5;

    root = deleteNode2(root, value);

    cout << "Tree after deletion : " << endl;
    levelOrderTraversal(root);

    return 0;
}
