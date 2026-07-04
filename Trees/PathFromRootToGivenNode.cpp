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

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

bool getPath(Node *root, int x, vector<int> &path)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }
    if (getPath(root->left, x, path) || getPath(root->right, x, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(Node *root, int x)
{
    vector<int> path;
    if (root == nullptr)
    {
        return path;
    }
    getPath(root, x, path);
    return path;
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

    int x = 7;
    vector<int> path = rootToNodePath(root, 7);
    display(path);

    return 0;
}