/*
Problem Name : Maximum Path sum
Problem Description : Given root of a binary tree, find the maximum sum possible in any non repeating
path of the tree
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
Intuition : Use max height of the tree algorithm, modify it to find maximum path sum
Use a separate variable which stores max path sum at any node, find the max path sum from left side,
and max path sum from right , maxSum = max(maxSum, leftMaxSum + rightMaxSum + currNode->data)
for maximum path sum along any node, it is calculated as currNode->data + max(leftSum , rightSum) from
currNode

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
int findMaxPathSum(Node *root, int &maxSum)
{
    if (root == nullptr)
    {
        return 0;
    }
    int leftSum = max(0, findMaxPathSum(root->left, maxSum));
    int rightSum = max(0, findMaxPathSum(root->right, maxSum));
    maxSum = max(maxSum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(Node *root)
{
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(-7);

    int maxSum = maxPathSum(root);

    cout << "Max Path Sum : " << maxSum;

    return 0;
}