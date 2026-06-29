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
Intuition : Use two stacks , first to store the left most nodes , second to store the traversed nodes
*/

void traversePostOrder1(Node *root)
{
    // Left , Right , Root
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st1;
    stack<Node *> st2;
    Node *node = root;
    st1.push(node);

    while (!st1.empty())
    {
        node = st1.top(); // current left most node
        st1.pop();
        st2.push(node);

        if (node->left)
        {
            st1.push(node->left);
        }
        if (node->right)
        {
            st1.push(node->right);
        }
    }

    while (!st2.empty())
    {
        node = st2.top();
        st2.pop();
        cout << node->data << ' ';
    }
    cout << endl;
}

void traversePostOrder2(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;
    Node *curr = root;
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            Node *temp = st.top()->right;

            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << ' ';

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << ' ';
                }
            }
            else
            {
                curr = temp;
            }
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

    cout << "Post Order  : "; // 4 5 2 6 7 3 1
    traversePostOrder2(root);

    return 0;
}