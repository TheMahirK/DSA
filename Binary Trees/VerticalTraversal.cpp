/*
Problem Name : Vertical Traversal of a binary tree
Problem Description : Given the root of a binary tree , find the vertical order traversal of the tree , from left to right and top
to bottom
Note : If the nodes are overlapping , traverse the smaller value node first
*/
#include <iostream>
#include <map>
#include <set>
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

/*
Intuition : 1. Use coordinate system to map tree nodes based on their coordinates , the root node is at 0,0 coordinate
in left side the x coordinate decreases , in down side y coordinate increases (our assumption)

Use level order traversa; and store multiset of nodes in a map along with their coordinates
Map assures that nodes are stored in left to right position , as left most coordinates are lowest , map store in lowest to highest order
We use multiset because multiple nodes with same values can be present
Also multi set ensures that if nodes are overlapping , they are stored in smaller to larger order

Time Complexity : O(N);
Aux. Space Req. : O(2N)
*/

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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

    cout << "Vertical Order Traversal : " << endl;
    vector<vector<int>> verticalOrder = verticalTraversal(root);
    display(verticalOrder);

    return 0;
}