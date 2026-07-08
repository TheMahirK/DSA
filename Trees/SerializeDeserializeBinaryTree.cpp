#include <iostream>
#include <string>
#include <sstream>
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

/*
Intuition : Use level order traversal using a queue, if any nodes left or right is nullptr , insert -1 in vector for nullptr
otherwise insert data in level order form

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

vector<int> serialize(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();
        if (currNode == nullptr)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(currNode->data);
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return ans;
}

/*
Intuition : Use same level order traversal to make the tree again , first create a node based on its value from vector, the next two
elements in the vector are curr nodes left and right values , put the left and right nodes in queue , this way we iteratively
build tree from top to bottom level wise

Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

Node *deSerialize(vector<int> &data)
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

void printInOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << ' ';
    printInOrder(root->right);
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

    cout << "Tree before serialization : ";
    printInOrder(root);
    cout << endl;

    vector<int> s = serialize(root);
    cout << "Serialized string : ";
    display(s);

    Node *root2 = deSerialize(s);
    cout << "Tree after deserialization : ";
    printInOrder(root2);

    return 0;
}