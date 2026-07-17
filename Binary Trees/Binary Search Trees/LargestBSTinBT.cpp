/*
Problem Name : Find largest BST in a Binary Tree
Problem Description : Given the root of a Binary tree, find the largest BST present as a tree/subtree
in the given Binary tree and return the total no. of nodes present in that BST

Note : A tree with single node is considered as BST with size = 1
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

bool checkValidity(TreeNode *root, int leftRange, int rightRange)
{
    if (root == nullptr)
    {
        return true;
    }
    int value = root->data;
    if (value <= leftRange || value >= rightRange)
    {
        return false;
    }
    return checkValidity(root->left, leftRange, value) && checkValidity(root->right, value, rightRange);
}

bool validateBST(TreeNode *root)
{
    int leftRange = INT_MIN, rightRange = INT_MAX;
    return checkValidity(root, leftRange, rightRange);
}

int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/*
Intuition : This is extreme brute force solution , validate every sub tree for BST condition , if
the sub tree is a valid BST , count the number of nodes and store the maximum nodes in ans

Time Complexity : O(N^2)
Aux. Space Req. : O(height)
*/
void largest(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return;
    }

    if (validateBST(root))
    {
        int nodes = countNodes(root);
        ans = max(ans, nodes);
        return;
    }
    largest(root->left, ans);
    largest(root->right, ans);
}

int largestBST1(TreeNode *root)
{
    // code here
    int ans = 1;

    largest(root, ans);
    return ans;
}

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

/*
Intuition : Use some data structure to store the , lower limit , upper limit and maxSize of any subtree
If current node is greater than largest node in left subtree and smaller than smallest node in right sub
current node satisfies BST condition , do this recursively for all subtrees
Whenever the subtree satisfies the BST condition , update the the lower bound , upper bound and maxSize

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
NodeValue getLargestBST(TreeNode *root)
{
    // An empty tree is a BST of size 0
    if (root == nullptr)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Get values from left and right subtrees of the current tree
    auto left = getLargestBST(root->left);
    auto right = getLargestBST(root->right);

    // Current node is greater than maxNode in left and smaller than minNode in right
    // It is a BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),
                         left.maxSize + right.maxSize + 1);
    }

    // Otherwise return [-inf, inf] so that parent can't be a valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST2(TreeNode *root)
{
    return getLargestBST(root).maxSize;
}

int main()
{

    vector<int> tree = {20, 15, 40, 14, 18, 30, 60, -1, 17, 16, 19, -1, -1, 50,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int largestSize = largestBST1(root);
    cout << "The size of the Largest BST in given Binary Tree : " << largestSize << " Node(s)";

    return 0;
}