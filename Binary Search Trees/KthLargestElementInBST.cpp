/*
Problem Name : Find the Kth largest node in BST
Problem Description : Given the root of a BST , and an integer k , find the kth largest element
present in BST
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

/*
Intuition :
Count number of nodes present in BST, kth largest element = (n-k+1)th smallest element
Use in order traversal to traverse elements in sorted order, decrement k for each node visited
when k becomes zero , we reach the kth smallest value node in BST

In a BST , the inorder traversal always traverses/gives values in sorted order
as in a BST, left values < root value < right values , and in order traversal traverses
left nodes , root nodes, right nodes

Time Complexity : O(logN)
Aux. Space Req. : O(height)
*/
void kthSmallest(Node *root, int &k, int &ans)
{
    if (root == nullptr || ans != -1)
    {
        return;
    }
    kthSmallest(root->left, k, ans);
    if (--k == 0)
    {
        ans = root->data;
        return;
    }
    kthSmallest(root->right, k, ans);
}

int countNodes1(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes1(root->left) + countNodes1(root->right);
}

int kthLargestElement1(Node *root, int k)
{
    int ans = -1, count = 0;
    int n = countNodes1(root);
    k = n - k + 1;
    kthSmallest(root, k, ans);
    return ans;
}

/*
Intuition : Do the same as above but using morris traversal to avoid aux. space req.

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

int countNodes2(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            count++;
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
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}
void inOrder(Node *root, int k, int &ans)
{
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            if (--k == 0)
            {
                ans = curr->data;
            }
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
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                if (--k == 0)
                {
                    ans = curr->data;
                }
                curr = curr->right;
            }
        }
    }
}

int kthLargestElement2(Node *root, int k)
{
    int ans = -1;
    int n = countNodes2(root);
    if (k > n)
    {
        return ans;
    }
    k = n - k + 1;
    inOrder(root, k, ans);
    return ans;
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 20,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    Node *root = buildTree(tree);

    int k = 16;

    int kthElement = kthLargestElement2(root, k);

    if (kthElement != -1)
    {
        cout << k << "th Largest Element in BST : " << kthElement;
    }
    else
    {
        cout << k << "th Largest element does not exist, as k > N";
    }
    cout << endl;

    return 0;
}
