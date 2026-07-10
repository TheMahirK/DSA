/*
Problem Name : Insert a node in BST
Problem Description : Given the root of a BST and an integer value key , insert a new node in BST
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

/*
Intuition : If the tree is already a valid BST and all node values are unique, the new node can be easily
inserted at its appropriate leaf node position

Use binary search to find its valid parent position , insert the node to its left or right as per value
This algorithm is simple and intuitive to implement but it inserts the node below last level
this increases the height of the tree

Time Complexity : O(logN)
Aux. Space Req. : O(1)

*/
Node *insertInBST(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    Node *curr = root;

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
                curr->right = new Node(value);
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
                curr->left = new Node(value);
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
    Node *root = buildTree(tree);

    levelOrderTraversal(root);

    root = insertInBST(root, 8);

    levelOrderTraversal(root);

    return 0;
}
