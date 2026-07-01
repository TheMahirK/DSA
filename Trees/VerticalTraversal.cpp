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

vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Vertical Order Traversal : " << endl;
    vector<vector<int>> verticalOrder = verticalTraversal(root);
    display(verticalOrder);

    return 0;
}