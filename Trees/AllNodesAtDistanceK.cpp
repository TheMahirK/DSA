/*
Problem Name : Find all the nodes at distance k from the target node
Problem Description : Given root of a binary tree, an integer k , and a node target
Find all the nodes which are at k distance from current node

It is given that the target node always exists in the tree
*/
#include <iostream>
#include <unordered_map>
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

void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentTracker)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        if (current->left)
        {
            parentTracker[current->left] = current;
            q.push(current->left);
        }
        if (current->right)
        {
            parentTracker[current->right] = current;
            q.push(current->right);
        }
    }
}

/*
Intuition : Firstly mark parent pointers and store them in a map so we can move in upward direction also
Now use outward traversal from target node
Traverse outwards (up , left , right from target node) and keep storing the nodes in queue
When we reach k distance , the nodes in queue are the required nodes

Time Complexity : O(2N) at worst case
Aux. Space Req. : O(3N)
N : for parent tracker, N : for visited tracker , N : for queue

*/

vector<int> getKDistanceNodes(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parentTracker;
    markParents(root, parentTracker);

    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int currLevel = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (currLevel == k)
        {
            break;
        }
        currLevel++;
        for (int i = 0; i < size; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parentTracker[current] && !visited[parentTracker[current]])
            {
                q.push(parentTracker[current]);
                visited[parentTracker[current]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int val = q.front()->data;
        q.pop();
        ans.push_back(val);
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

    TreeNode *seven = root->right->right;

    int k = 2;

    vector<int> nodes = getKDistanceNodes(root, seven, k);
    display(nodes);

    return 0;
}