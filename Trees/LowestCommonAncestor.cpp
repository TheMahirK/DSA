/*
Problem Name : Find lowest/closest common ancestor
Problem Description : Given the root of a binary tree and two nodes p and q, find the lowest/closest
common ancestor in the tree

A lowest/closest common ancestor is the first intersection found when we traverse from both nodes from
bottom to top order
Note : A node itself can be its closest common ancestor
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

/*
Intuition : Use concept
If node p exists below left/right side we say it exists
If node q exists below left/right side we say it exists

The node below which both the nodes exist is the closest/lowest ancestor
We can implement this using recursive traversal

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
Node *getLowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }
    Node *left = getLowestCommonAncestor(root->left, p, q);
    Node *right = getLowestCommonAncestor(root->right, p, q);

    if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    else
    {
        return root;
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

    Node *node1 = root->left->left;
    Node *five = root->left->right;
    Node *node2 = new Node(8);
    five->right = node2;

    Node *closestAncestor = getLowestCommonAncestor(root, node1, node2);

    cout << "The closest ancestor of " << node1->data << " and " << node2->data << " : "
         << closestAncestor->data;

    return 0;
}