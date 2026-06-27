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

/*
Algorithm Used : Depth first search (DFS)
Time Complexity : O(N)
Aux. Space Req. : O(log N )
*/

// 1. Left subtree
// 2. Root node
// 3. Right subtree
void traverseInorder(Node *root)
{
    if (root != nullptr)
    {
        traverseInorder(root->left);
        cout << root->data << ' ';
        traverseInorder(root->right);
    }
}

// 1. Root node
// 2. Left subtree
// 3. Right subtree

void traversePreorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << ' ';
        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

// 1. Left subtree
// 2. Right subtree
// 3. Root node

void traversePostorder(Node *root)
{
    if (root != nullptr)
    {
        traversePostorder(root->left);
        traversePostorder(root->right);
        cout << root->data << ' ';
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder   : "; // 4 2 5 1 6 3 7
    traverseInorder(root);
    cout << endl;

    cout << "Preorder  : "; // 1 2 4 5 3 6 7
    traversePreorder(root);
    cout << endl;

    cout << "Postorder : "; // 4 5 2 6 7 3 1
    traversePostorder(root);
    cout << endl;

    return 0;
}