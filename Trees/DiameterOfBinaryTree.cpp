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

/*
Intuition : The diameter of a the tree is max. left height + max. right height
recursively find diameter for left tree and right tree. At every step keep checking for maximum diameter
Time Complexity : O(N^2)
Aux. Space Req. : O(height of tree)
*/

// This is a helper function for getTreeDiameter1
void getTreeDiameter(Node *root, int &diameter)
{
    if (root == nullptr)
    {
        return;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    diameter = max(diameter, leftHeight + rightHeight);

    getTreeDiameter(root->left, diameter);
    getTreeDiameter(root->right, diameter);
}

int getTreeDiameter1(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int diameter = 0;
    getTreeDiameter(root, diameter);
    return diameter;
}

/*
Intuition : Height of tree with 1 node (root node) is 1
we can use recurrence relation maxHeight = 1 + maxHeight(left tree , right tree)
*/

int getMaxHeight(Node *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftHeight = getMaxHeight(root->left, diameter);
    int rightHeight = getMaxHeight(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

/*
Intuition : The diameter of a the tree is max. left height + max. right height
Use modify max height function to recursively find diameter of the tree
Time Complexity : O(N)
Aux. Space Req. : O(height of tree)
*/
int getTreeDiameter2(Node *root)
{
    int diameter = 0;
    getMaxHeight(root, diameter);
    return diameter;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    Node *six = root->right->left;
    root->right->right = new Node(7);
    Node *seven = root->right->right;
    seven->right = new Node(0);

    six->right = new Node(9);
    six->right->right = new Node(10);

    int diameter = getTreeDiameter2(root);

    cout << "The Diameter of the tree is : " << diameter;

    return 0;
}