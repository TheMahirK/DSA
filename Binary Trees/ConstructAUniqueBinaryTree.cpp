/*
Problem Name : Construct a unique binary tree
Problem Description : Given inorder traversal and pre order traversal , construct a unique binary
tree which has the same in order , same pre order and same post order traversal

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

void display(vector<int> &traversal)
{
    for (auto x : traversal)
    {
        cout << x << ' ';
    }
    cout << endl;
}

// 1. Left subtree
// 2. Root node
// 3. Right subtree
void traverseInorder(TreeNode *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        traverseInorder(root->left, traversal);
        // cout << root->data << ' ';
        traversal.push_back(root->data);
        traverseInorder(root->right, traversal);
    }
}

vector<int> inOrder(TreeNode *root)
{
    vector<int> traversal;
    traverseInorder(root, traversal);
    return traversal;
}

// 1. Root node
// 2. Left subtree
// 3. Right subtree

void traversePreorder(TreeNode *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        // cout << root->data << ' ';
        traversal.push_back(root->data);
        traversePreorder(root->left, traversal);
        traversePreorder(root->right, traversal);
    }
}

vector<int> preOrder(TreeNode *root)
{
    vector<int> traversal;
    traversePreorder(root, traversal);
    return traversal;
}
// 1. Left subtree
// 2. Right subtree
// 3. Root node

void traversePostorder(TreeNode *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        traversePostorder(root->left, traversal);
        traversePostorder(root->right, traversal);
        // cout << root->data << ' ';
        traversal.push_back(root->data);
    }
}

vector<int> postOrder(TreeNode *root)
{
    vector<int> traversal;
    traversePostorder(root, traversal);
    return traversal;
}

/*
Intuition : Use the concept that pre order always start from root for any tree/subtree
and in order always has root in middle, left sub tree elements in left , right sub tree elements in right
with the combination of these two information, we can recursively build the tree

Time Complexity : O(2N)
Aux. Space Req. : O(2N)
N : for map storing in order elements, N for recursively building each node

*/

TreeNode *buildTree(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder,
                int inStart, int inEnd, map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode *getTree(vector<int> &preOrder, vector<int> &inOrder)
{
    map<int, int> inMap;

    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }
    TreeNode *root = buildTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return root;
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

    vector<int> in = inOrder(root);
    cout << "In order : ";
    display(in);

    vector<int> pre = preOrder(root);
    cout << "Pre order : ";
    display(pre);

    vector<int> post = postOrder(root);
    cout << "Post order : ";
    display(post);

    root = getTree(pre, in);

    vector<int> in2 = inOrder(root);
    cout << "New In order : ";
    display(in2);

    vector<int> pre2 = preOrder(root);
    cout << "New Pre order : ";
    display(pre2);

    vector<int> post2 = postOrder(root);
    cout << "New Post order : ";
    display(post2);

    return 0;
}