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
Intuition : 
*/

void traversePreOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        cout << root->data << ' ';
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
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

    cout << "Preorder  : "; // 1 2 4 5 3 6 7
    traversePreOrder(root);
    cout << endl;

    return 0;
}