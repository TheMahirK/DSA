#include <iostream>
#include <map>
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

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> preOrder(Node *root)
{
    vector<int> ans;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // cout << curr->data << ' ';
            ans.push_back(curr->data);
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
                // cout << curr->data << ' ';
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    // cout << endl;
    return ans;
}
/*
Intuition : This is extreme brute force solution, create the tree from ground up
Insert every node to its correct position

Time Complexity : O(N * logN)
Aux. Space Req. : O(1)
*/
Node *insertInBST(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    Node *curr = root;

    while (true)
    {
        if (value >= curr->data)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(value);
                break;
            }
        }

        else
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(value);
                break;
            }
        }
    }
    return root;
}

Node *constructBST1(vector<int> &preOrder)
{
    Node *root = new Node(preOrder[0]);

    for (int i = 1; i < preOrder.size(); i++)
    {
        root = insertInBST(root, preOrder[i]);
    }
    return root;
}

/*
Intuition : Get in order traversal by sorting pre order traversal
Construct a unique binary tree with pre order and in order traversal combined

Time Complexity : O(N * logN)
Aux. Space Req. : O(N)
*/
Node *construct(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder,
                int inStart, int inEnd, map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    Node *root = new Node(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = construct(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inMap);
    root->right = construct(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);

    return root;
}
Node *constructBST2(vector<int> &preOrder)
{
    vector<int> inOrder(preOrder.begin(), preOrder.end());
    sort(inOrder.begin(), inOrder.end());

    map<int, int> inMap;

    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }
    Node *root = construct(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return root;
}


/*
Intuition : Use range concept from validate BST , if the element can be inserted in left , value < currNode
insert in left, if element can be inserted in right , insert in right , by checking upper bound condition
do this recursively on all elements , and backtrack to the root node

Time Complexity : O(N)
Aux. Space Req. : 
*/
Node *build(vector<int> &preOrder, int &i, int bound)
{
    if (i == preOrder.size() || preOrder[i] > bound)
    {
        return nullptr;
    }
    Node *root = new Node(preOrder[i++]);
    root->left = build(preOrder, i, root->data);
    root->right = build(preOrder, i, bound);
    return root;
}
Node *constructBST3(vector<int> &preOrder)
{
    int i = 0;
    return build(preOrder, i, INT_MAX);
}
int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    vector<int> pre = preOrder(root);

    cout << "Pre order traversal : ";
    display(pre);

    Node *root2 = constructBST3(pre);
    vector<int> pre2 = preOrder(root2);

    cout << "New tree pre order traversal : ";
    display(pre2);

    return 0;
}
