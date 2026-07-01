/*
Problem Name : Check Identical Trees
Problem Descriptuon : Given roots of two trees
return true if both the trees are identical (in terms of values and their arrangements) otherwise
return false
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
Intuition : We can use any traversal (in order / pre order / post order) on both trees simultaneously
to check for equality of nodes and equality of their arrangement

Identical trees have same traversal , non identical trees do not have same traversal

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return (root1 == root2);
    }
    return (root1->data == root2->data) && isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
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

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    bool isSame = isIdentical(root, root2);

    if (isSame)
    {
        cout << "Both the trees are identical to each other";
    }
    else
    {
        cout << "The trees are NOT identical to each other";
    }

    return 0;
}