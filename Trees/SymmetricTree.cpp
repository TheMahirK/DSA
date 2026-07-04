/*
Problem Name : Check Symmetric Tree
Problem Description : Given the root of a tree, check whether the given tree is symmetric or not
A tree is said to be symmetric if the left half of tree and right half of tree are both mirror images
of each other
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

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

bool checkSymmeric(Node *root1, Node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return (root1 == root2);
    }

    if (root1->data != root2->data)
    {
        return false;
    }
    return checkSymmeric(root1->left, root2->right) && checkSymmeric(root1->right, root2->left);
}

/*
Intuition : 1. Symmetric things have same mirror image
2. Mirror flips the directions , makes right point to left , left point to right
Traverse the left half and right half of the tree in pre order symmetrically to check for symmetry
i.e. if one goes left , other goes right

Time Complexity : O(N)
Aux. Space Req. : O(height)

*/
bool isSymmetric(Node *root)
{
    return checkSymmeric(root->left, root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool symmetric = isSymmetric(root);

    if (symmetric)
    {
        cout << "Given Tree is symmetric";
    }
    else
    {
        cout << "Given Tree is NOT symmetric";
    }

    return 0;
}