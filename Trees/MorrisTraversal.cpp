/*
Problem Name : Morris Traversal
Problem Description : Given the root of a binary tree Traverse tree in In order, pre order without using any extra space
that means Aux. Space Req. should be O(1)
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
Intuition : Use thread connection concept to go back to root
Steps
1. Remember current node
2. Go to right most node of left sub tree
3. Connect right most node to current node
4. Traverse tree normally
5. When reached at right most node , go directly back to parent node via connection
6. Repeat the steps 1 to 5 for right side

This prints as Left, Root, Right

Time Complexity : ~ O(2N)
Aux. Space Req. : O(1)
*/

void inOrder(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                cout << curr->data << ' ';
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

// Do the same as in order traversal above but change the print condition to print as Root, Left, Right
void preOrder(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                cout << curr->data << ' ';
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout << endl;
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

    cout << "Preorder traversal : ";
    preOrder(root);

    cout << "Inorder traversal : ";
    inOrder(root);

    return 0;
}