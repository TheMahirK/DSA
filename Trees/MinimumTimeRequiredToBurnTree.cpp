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

void markParents(Node *root, unordered_map<Node *, Node *> &parentTracker,
                 Node *&target, int targetValue)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        if (currNode->data == targetValue)
        {
            target = currNode;
        }

        if (currNode->left)
        {
            parentTracker[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            parentTracker[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}

/*
Intuition : 1. Mark parent pointers for DFS traversal
If target node is given , start from target node
If target node value is given , find target node during marking of parent pointers

Use outward level traversal (DFS) from target node, for each level 1 unit of time is required

Time Complexity : O(2N) at worst case
Aux. Space Req. : O(3N)
N : for parent tracker, N : for visited tracker , N : for queue
*/

int minAmountOfTime(Node *root, int start)
{
    int ans = 0;
    Node *target = nullptr;
    unordered_map<Node *, Node *> parentTracker;
    markParents(root, parentTracker, target, start);

    // Bonus point if target node is root node , ans = max Height of the tree
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;

    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *currNode = q.front();
            q.pop();

            if (currNode->left != nullptr && !visited[currNode->left])
            {
                q.push(currNode->left);
                visited[currNode->left] = true;
                flag = 1;
            }
            if (currNode->right != nullptr && !visited[currNode->right])
            {
                q.push(currNode->right);
                visited[currNode->right] = true;
                flag = 1;
            }
            if (parentTracker[currNode] && !visited[parentTracker[currNode]])
            {
                q.push(parentTracker[currNode]);
                visited[parentTracker[currNode]] = true;
                flag = 1;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(8);
    root->left->left->right = new Node(7);

    int target = 1;
    int minTime = minAmountOfTime(root, target);
    cout << "Minimum Amount of time to burn tree from target node " << target << " : " << minTime
         << " units";

    return 0;
}
