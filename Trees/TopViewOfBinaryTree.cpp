/*
Problem Name : Top view of a binary tree
Problem Description : Given the root of a binary tree, find the top view nodes of the binary tree
*/
#include <iostream>
#include <map>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data, TreeNode *left = nullptr, TreeNode *right = nullptr)
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
Intuition : Use vertical traversal of tree concept , just store the x coordinate (vertical line number)
Store only the first node at that line coordinate, otherwise ignore
Map will store nodes from left most line number (lowest) to right most line number (highest)

Time Complexity : O(N)
Aux. Space Req. : O(2N)
*/
vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    // Line , node value
    map<int, int> mpp;

    // TreeNode , line
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }

        if (node->left != nullptr)
        {
            q.push({node->left, line - 1});
        }
        if (node->right != nullptr)
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> topView = getTopView(root);
    display(topView);

    return 0;
}