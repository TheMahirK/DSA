/*
Problem Name : Bottom view of a binary tree
Problem Description : Given the root of a binary tree, find the Bottom view nodes of the binary tree
*/
#include <iostream>
#include <map>
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

/*
Intuition : Use vertical traversal of tree concept and top view concept
If another node comes at that line, replace the previous node with new node
Map will store nodes from left most line number (lowest) to right most line number (highest)

Time Complexity : O(N)
Aux. Space Req. : O(2N)
*/
vector<int> getBottomView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    // Line no. , node value
    map<int, int> mpp;

    // Node , line number
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
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

    vector<int> bottomView = getBottomView(root);
    display(bottomView);

    return 0;
}