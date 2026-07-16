/*
Problem Name : Lowest/Closest Common Ancestor in BST
Problem Description : Given the root of a BST and two nodes p and q, find the lowest/closest common
ancestor of the nodes p and q

A lowest/closest common ancestor is the first intersection found when we traverse from both nodes from
bottom to top order
Note : A node itself can be its closest common ancestor

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

TreeNode *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    TreeNode *root = new TreeNode(data[i++]);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(data[i]);
            currNode->left = leftNode;
            q.push(leftNode);
        }
        i++;
        if (data[i] == -1)
        {
            currNode->right = nullptr;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(data[i]);
            currNode->right = rightNode;
            q.push(rightNode);
        }
        i++;
    }
    return root;
}

TreeNode *findNode(TreeNode *root, int value)
{
    if (root == nullptr || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return findNode(root->left, value);
    }
    else
    {
        return findNode(root->right, value);
    }
}

/*
Intuition : Use binary search algorithm to find parent
If both the nodes are lower than curr node , the common ancestor should be in left subtree
If both the nodes are greater than curr node, the common ancestor should be in right sub tree

Else, that means one node is in left sub tree , one node is in right sub tree, the curr node is
the closest common ancestor

Repeat these steps recursively to find the closest common ancestor

Time Complexity : O(logN)
Aux. Space Req. : O(height)
*/
TreeNode *findCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return root;
    }
    if (p->data < root->data && q->data < root->data)
    {
        return findCommonAncestor1(root->left, p, q);
    }

    if (p->data > root->data && q->data > root->data)
    {
        return findCommonAncestor1(root->right, p, q);
    }
    return root;
}

/*
Intuition : This is the iterative implementation of prev algorithm to save recursive stack space use

Time Complexity : O(logN)
Aux. Space Req. : O(1)
*/
TreeNode *findCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *curr = root;
    TreeNode *ans = root;

    while (curr != nullptr)
    {
        if (p->data < curr->data && q->data < curr->data)
        {
            ans = curr;
            curr = curr->left;
        }
        if (p->data > curr->data && q->data > curr->data)
        {
            ans = curr;
            curr = curr->right;
        }
        else
        {
            ans = curr;
            break;
        }
    }
    return ans;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    TreeNode *root = buildTree(tree);

    TreeNode *six = findNode(root, 6);

    TreeNode *three = findNode(root, 3);

    TreeNode *commonAncestor = findCommonAncestor2(root, three, six);

    cout << "The closest common ancestor of " << three->data << " and " << six->data << " is : "
         << commonAncestor->data;

    return 0;
}
