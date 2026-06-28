/*
Level order traversal
Print elements level wise, from topmost level to the bottom most level

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

void display(vector<vector<int>> &levels)
{
    for (auto level : levels)
    {
        for (auto ele : level)
        {
            cout << ele << ' ';
        }
        cout << endl;
    }
    cout << endl;
}


/*
Intuition : Use a queue to store nodes of a particular level from left to right, pop from front to get
level order

Time Complexity : O(N)
Aux. Space Req : O(no. of leaf nodes)
*/
vector<vector<int>> levelOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currLevel;

        for (int i = 0; i < size; i++)
        {
            Node *currRoot = q.front();
            q.pop();

            if (currRoot->left)
            {
                q.push(currRoot->left);
            }
            if (currRoot->right)
            {
                q.push(currRoot->right);
            }
            currLevel.push_back(currRoot->data);
        }
        ans.push_back(currLevel);
    }
    return ans;
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

    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    display(levelOrder);

    return 0;
}