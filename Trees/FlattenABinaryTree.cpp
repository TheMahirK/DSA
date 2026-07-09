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

void display(Node *root)
{
    Node *c = root;
    while (c != nullptr)
    {
        cout << c->data << ' ';
        c = c->right;
    }
    cout << endl;
}

void preOrder(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = curr;
                cout << curr->data << ' ';
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

/*
Intuition : Use reverse post order traversal that is Right, Left, Root
Keep updating updating prev pointer and making right connection to prev pointer and left pointer to null

Time Complexity : O(N)
Aux. Space Req. : O(height)
*/
void flatten(Node *root, Node *&prev)
{
    if (root == nullptr)
    {
        return;
    }
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void flattenBinaryTree1(Node *root)
{
    Node *node = root;
    Node *prev = nullptr;
    flatten(node, prev);
}

/*
Intuition : Use a manually created stack to simulate the above function iteratively
Store left node on top , connect left node to right side of tree
Repeat this for all sub trees

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/
void flattenBinaryTree2(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *currNode = st.top();
        st.pop();

        if (currNode->right)
        {
            st.push(currNode->right);
        }
        if (currNode->left)
        {
            st.push(currNode->left);
        }

        if (!st.empty())
        {
            currNode->right = st.top();
        }
        currNode->left = nullptr;
    }
}

void flattenBinaryTree3(Node *root)
{
    Node *currNode = root;
    while (currNode != nullptr)
    {
        if (currNode->left != nullptr)
        {
            Node *prev = currNode->left;

            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = currNode->right;
            currNode->right = currNode->left;
            currNode->left = nullptr;
        }
        currNode = currNode->right;
    }
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

    preOrder(root);

    flattenBinaryTree3(root);

    display(root);

    return 0;
}