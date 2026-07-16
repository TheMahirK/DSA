/*
Problem Name : Find path from root to given node
Problem Description : Given the root of a tree and an int x or node x, find the path from root to
given node x.
It means find all the nodes that come in between when we travel from root to node x
*/
#include <iostream>
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
Intuition : Use recursive pre order traversal to go deep in paths , during traversal we keep taking nodes
into answer path, if we reach end (left == null ptr and right == nullptr)   the node does not exist
in that path so we remove the added nodes , and try different path. if we find the correct path
we keep all the nodes that came during that path this way we get path to the given node

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/

bool getPath(TreeNode *root, int x, vector<int> &path)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }
    if (getPath(root->left, x, path) || getPath(root->right, x, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode *root, int x)
{
    vector<int> path;
    if (root == nullptr)
    {
        return path;
    }
    getPath(root, x, path);
    return path;
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

    int x = 7;
    vector<int> path = rootToNodePath(root, 7);
    display(path);

    return 0;
}