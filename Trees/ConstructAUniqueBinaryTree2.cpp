/*
Problem Name : Construct a unique binary tree
Problem Description : Given inorder traversal and post order traversal , construct a unique binary
tree which has the same in order , same pre order and same post order traversal

*/

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
void traverseInorder(Node *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        traverseInorder(root->left, traversal);
        // cout << root->data << ' ';
        traversal.push_back(root->data);
        traverseInorder(root->right, traversal);
    }
}

vector<int> inOrder(Node *root)
{
    vector<int> traversal;
    traverseInorder(root, traversal);
    return traversal;
}

// 1. Root node
// 2. Left subtree
// 3. Right subtree

void traversePreorder(Node *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        // cout << root->data << ' ';
        traversal.push_back(root->data);
        traversePreorder(root->left, traversal);
        traversePreorder(root->right, traversal);
    }
}

vector<int> preOrder(Node *root)
{
    vector<int> traversal;
    traversePreorder(root, traversal);
    return traversal;
}
// 1. Left subtree
// 2. Right subtree
// 3. Root node

void traversePostorder(Node *root, vector<int> &traversal)
{
    if (root != nullptr)
    {
        traversePostorder(root->left, traversal);
        traversePostorder(root->right, traversal);
        // cout << root->data << ' ';
        traversal.push_back(root->data);
    }
}

vector<int> postOrder(Node *root)
{
    vector<int> traversal;
    traversePostorder(root, traversal);
    return traversal;
}

/*
Intuition : Use the concept that post order always end with root for any tree/subtree
and in order always has root in middle, left sub tree elements in left , right sub tree elements in right
with the combination of these two information, we can recursively build the tree

Time Complexity : O(2N)
Aux. Space Req. : O(2N)
N : for map storing in order elements, N for recursively building each node

*/

Node *buildTree(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inOrder,
                int inStart, int inEnd, map<int, int> &inMap)
{
    if (postStart > postEnd || inStart > inEnd)
    {
        return nullptr;
    }

    Node *root = new Node(postOrder[postEnd]);
    int inRoot = inMap[postOrder[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(postOrder, postStart, postStart + numsLeft - 1, inOrder, inStart,
                           inRoot - 1, inMap);
    root->right = buildTree(postOrder, postStart + numsLeft, postEnd - 1, inOrder, inRoot + 1, inEnd, inMap);

    return root;
}

Node *getTree(vector<int> &postOrder, vector<int> &inOrder)
{

    if (postOrder.size() != inOrder.size())
    {
        return nullptr;
    }

    map<int, int> inMap;

    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }
    Node *root = buildTree(postOrder, 0, postOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return root;
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

    vector<int> in = inOrder(root);
    cout << "In order : ";
    display(in);

    vector<int> pre = preOrder(root);
    cout << "Pre order : ";
    display(pre);

    vector<int> post = postOrder(root);
    cout << "Post order : ";
    display(post);

    root = getTree(post, in);

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