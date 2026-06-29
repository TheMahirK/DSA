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

/*
Intuition : Simulate the recursive stack using manually created stack
*/

void traverseInOrder(Node *root)
{
    // Left , Root, Right
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;

    Node *node = root;

    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            cout << node->data << ' ';
            node = node->right;
        }
    }
    cout << endl;
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

    cout << "Inorder  : "; // 4 2 5 1 6 3 7
    traverseInOrder(root);
    cout << endl;

    return 0;
}