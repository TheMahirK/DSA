/*
Problem Name : Get in order successor
Problem Description : Given the root of a BST and a node/integer target node/value , find the in order
successor of the given node/value

The in order successor is the right next value that comes after the given node
If the inorder successor does not exist , return -1
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

/*
Intuition : Use binary search to find the successor, the inorder traversal follows as left,root, right
Keep updating the successor along the way

Time Complexity : O(log N)
Aux. Space Req. : O(1)
*/
int getSuccessor(Node *root, int target)
{
    int ans = -1;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (target < curr->data)
        {
            ans = curr->data;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return ans;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    int target = 7;
    int successor = getSuccessor(root, target);

    if (successor != -1)
    {
        cout << "The In order successor of target node " << target << " is : " << successor;
    }
    else
    {
        cout << "The In order successor of target node " << target << " does NOT exist";
    }

    return 0;
}
