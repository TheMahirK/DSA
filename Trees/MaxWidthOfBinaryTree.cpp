/*
Problem Name : Maximum width of a binary tree
Problem Description : Given the root of a binary tree , find the maximum width possible of the tree
The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null
nodes), where the null nodes between the end-nodes that would be present in a complete binary tree
extending down to that level are also counted into the length calculation.
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

/*
Intuition : Use level order traversal , assign each node of each level an id
if curr node has id i , left node will have id 2*i + 1
and right node will have id 2*i + 2

but it wil overflow limit if there are lots of nodes and lots of levels

so we improve by using
if curr node has id i , left node will have id 2* [i - mini of the level]+1
and right node will have id 2*[i-mini of the level] + 1

max width is calculated as max of all levels (left most node id - right most node id + 1)
based on indexing of levels from 0

Time Complexity : O(N)
Aux. Space Req. : O(N)

*/

int getWidth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        auto it = q.front();
        int mini = it.second;
        int first, last;

        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            int currId = it.second - mini;
            TreeNode *node = it.first;
            if (i == 0)
            {
                first = currId;
            }
            if (i == size - 1)
            {
                last = currId;
            }
            if (node->left != nullptr)
            {
                q.push({node->left, 2 * currId + 1});
            }
            if (node->right != nullptr)
            {
                q.push({node->right, 2 * currId + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int width = getWidth(root);

    cout << "Maximum Width of the tree : " << width;

    return 0;
}