/*
Problem Name : Validate a BST
Problem Description : Given the root of a binary tree , return true if the given binary tree is a BST
otherwise return false
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
Intuition : Use range parameter to check the validity , a tree is valid if curr node value is greater than lower limit and
less than upper limit, when we move left , the upper limit becomes curr node value. When we move right , the lower limit
becomes curr node value

If current node satisfies the validity condition , we verify for left half of the tree and right half of the tree with changed
lower and upper limits

Otherwise we return false, doing this recursively for whole tree and ANDing all the outputs we get output for the whole tree

Time Complexity : O(N)
Aux. Space Req. : O(logN)
*/
bool checkValidity(Node *root, int leftRange, int rightRange)
{
    if (root == nullptr)
    {
        return true;
    }
    int value = root->data;
    if (value < leftRange || value > rightRange)
    {
        return false;
    }
    return checkValidity(root->left, leftRange, value) && checkValidity(root->right, value, rightRange);
}

bool validateBST(Node *root)
{
    int leftRange = INT_MIN, rightRange = INT_MAX;
    return checkValidity(root, leftRange, rightRange);
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    bool isValid = validateBST(root);

    if (isValid)
    {
        cout << "Given Binary tree is a valid BST";
    }
    else
    {
        cout << "Given Binary tree is NOT a valid BST";
    }

    return 0;
}
