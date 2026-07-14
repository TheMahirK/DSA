/*
Problem Name : Two sum in a BST
Problem Description : Given the root of a BST, and a value k , return true if there exist
at least one pair two different values whose sum equals k
other wise return false
*/

#include <iostream>
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

Node *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    Node *root = new Node(data[i++]);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            Node *leftNode = new Node(data[i]);
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
            Node *rightNode = new Node(data[i]);
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
    stack<Node *> st;
    // false for ascending order , means next
    // true for descending order , means before
    bool reverse = true;
    void pushAll(Node *node)
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
        Node *curr = st.top();
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
    BSTIterator(Node *root, bool isReverse)
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
bool findTarget(Node *root, int k)
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
    Node *root = buildTree(tree);

    int k = 38;

    bool ans = findTarget(root, k);

    cout << ans;

    return 0;
}
