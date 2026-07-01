/*
Problem Name : Zig zag traversal of a Binary Tree
Problem Description : Given root of a binary tree , find out the zigZag traversal of the binary tree
start from left to right
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
Use flag to reverse the even levels to get zigZag traversal
reverse current level for every even levels

Time Complexity : O(N)
Aux. Space Req : O(no. of leaf nodes)
*/
vector<vector<int>> zigZagTraversal1(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    bool flag = true;
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
        if (flag == false)
        {
            reverse(currLevel.begin(), currLevel.end());
        }
        ans.push_back(currLevel);
        flag = !flag;
    }
    return ans;
}

/*
Intuition : This is improved version of previous function which avoids reverse function to improve
Time Comlexity
Use index variable to smartly insert in left to right order or right to left order to avoid reversing on
every even level

Time Complexity : O(N)
Aux. Space Req : O(no. of leaf nodes)
*/

vector<vector<int>> zigZagTraversal2(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    bool flag = true;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> currLevel(size);

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
            int index = (flag) ? i : size - i - 1;
            currLevel[index] = currRoot->data;
        }
        ans.push_back(currLevel);
        flag = !flag;
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

    vector<vector<int>> zigZagOrder = zigZagTraversal2(root);
    display(zigZagOrder);

    return 0;
}