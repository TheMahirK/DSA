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

void leftView(Node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}

/*
Intuition : Use recursive traversal from left to right while maintaining level and ans data structure
Whenever we visit the first node of a new level, the data structure has size == curr Level
for ex. at 0th level size == 0
so we push the first node of that level

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/

vector<int> getLeftSideView1(Node *root)
{
    vector<int> ans;
    int level = 0;

    leftView(root, level, ans);

    return ans;
}

/*
Intuition : Do the level order traversal along with levels from 0 onwards from left to right
Whenever level == ans.size , we push the node value otherwise ignore
this works because at every level only once the level == ans.size , which is the first node from left

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

vector<int> getLeftSideView2(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    // Node , level
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int level = it.second;
        if (level == ans.size())
        {
            ans.push_back(node->data);
        }
        if (node->left != nullptr)
        {
            q.push({node->left, level + 1});
        }
        if (node->right != nullptr)
        {
            q.push({node->right, level + 1});
        }
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
    Node *five = root->left->right;
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    five->right = new Node(8);

    vector<int> leftSideView = getLeftSideView2(root);
    display(leftSideView);

    return 0;
}
