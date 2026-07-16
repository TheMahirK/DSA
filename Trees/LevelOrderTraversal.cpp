/*
Level order traversal
Print elements level wise, from topmost level to the bottom most level

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
Intuition : Use a queue to store nodes of a particular level from left to right, pop from front to get
level order

Time Complexity : O(N)
Aux. Space Req : O(no. of leaf nodes)
*/
vector<vector<int>> levelOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currLevel;

        for (int i = 0; i < size; i++)
        {
            TreeNode *currRoot = q.front();
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    display(levelOrder);

    return 0;
}