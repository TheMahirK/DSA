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
Intuition : Height of tree with 1 node (root node) is 1
we can use recurrence relation maxHeight = 1 + maxHeight(left tree , right tree)
*/

int getMaxHeight(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
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

    int maxHeight = getMaxHeight(root);
    cout << "Maximum height/depth of the tree : " << maxHeight;

    return 0;
}