/*
Problem Name : Two sum in a BST
Problem Description : Given the root of a BST, and a value k , return true if there exist
at least one pair two different values whose sum equals k
other wise return false
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

// Single BST iterator class to handle both before() and next()
class BSTIterator
{
private:
    stack<TreeNode *> st;
    // false for ascending order , means next
    // true for descending order , means before
    bool reverse = true;
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);

            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    bool hasNext()
    {
        return !(st.empty());
    }

    int next()
    {
        TreeNode *curr = st.top();
        st.pop();
        if (!reverse)
        {
            pushAll(curr->right);
        }
        else
        {
            pushAll(curr->left);
        }
        return curr->data;
    }
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
};

/*
Intuition : Use BST Iterator for next()-> for pre order in ascending order, before()-> for pre order in descending order
iteratively use two pointer approach , one from lowest/left most side in ascending order and one from highest/right most side
in descending order to find the two separate values whose sum equals k
*/
bool findTarget(TreeNode *root, int k)
{
    if (root == nullptr)
    {
        return false;
    }
    // for next
    BSTIterator left(root, false);

    // for before
    BSTIterator right(root, true);

    int i = left.next();
    int j = right.next();

    while (i < j)
    {
        if (i + j == k)
        {
            return true;
        }
        else if (i + j < k)
        {
            i = left.next();
        }
        else
        {
            j = right.next();
        }
    }
    return false;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    int k = 38;

    bool ans = findTarget(root, k);

    cout << ans;

    return 0;
}
