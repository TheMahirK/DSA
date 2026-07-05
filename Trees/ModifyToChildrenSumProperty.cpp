/*
Problem Name : Modify the tree so that it follows children sum property
Problem Description : Given the root of a binary tree , modify the tree such that it follows children sum property throughout
the tree , you can only use +1 increment any number of times to any node , decrement of any sort is not allowed

The children sum property means that for every node , the parent node value is exactly equal to the sum of its left child node
and right child node values
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
Intuition : Follow this algorithm
if root value == sum of child values do nothing
If root value is less than < child node value sum , make root node value = sum of child node values
Otherwise distribute the same root value to both the child nodes so that above condition is satisfied

Do this recursively , reassign the values at the time of backtracking

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
void modifyTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    int sum = 0;

    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }

    if (sum >= root->data)
    {
        root->data = sum;
    }
    else
    {
        if (root->left)
        {
            root->left->data = sum;
        }
        if (root->right)
        {
            root->right->data = sum;
        }
    }
    modifyTree(root->left);
    modifyTree(root->right);

    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = tot;
    }
}

void display(vector<vector<int>> &levels)
{
    for (auto level : levels)
    {
        for (auto ele : level)
        {
            cout << ele << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// This is just for display purpose only
vector<vector<int>> levelOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currLevel;

        for (int i = 0; i < size; i++)
        {
            Node *currRoot = q.front();
            q.pop();

            if (currRoot->left)
            {
                q.push(currRoot->left);
            }
            if (currRoot->right)
            {
                q.push(currRoot->right);
            }
            currLevel.push_back(currRoot->data);
        }
        ans.push_back(currLevel);
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

    vector<vector<int>> levelOrder1 = levelOrderTraversal(root);
    cout << "Original tree : " << endl;
    display(levelOrder1);

    modifyTree(root);

    vector<vector<int>> levelOrder2 = levelOrderTraversal(root);
    cout << "Modified tree : " << endl;
    display(levelOrder2);

    return 0;
}
