/*
Problem Name : Recover a BST
Problem Description : Given the root of a BST, but two nodes in the BST has their values swapped, find the two nodes and swap
their values to recover the BST
*/

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data, TreeNode *left = nullptr, TreeNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

TreeNode *buildTree(vector<int> &data)
{
    if (data.size() == 0)
    {
        return nullptr;
    }
    int i = 0;
    TreeNode *root = new TreeNode(data[i++]);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *currNode = q.front();
        q.pop();

        if (data[i] == -1)
        {
            currNode->left = nullptr;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(data[i]);
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
            TreeNode *rightNode = new TreeNode(data[i]);
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

void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
/*
Intuition : This is extreme brute force solution , get in order traversal of unrecovered tree store in a vector,
swap the two changed values so that the vector stores correct in order traversal
Traverse the unrecovered tree again in order while matching values with correct values stored in vector, when
the value differ , we assign the value stored in the vector

Time Complexity : O(3N)
N : for getting incorrect in order, N : for swapping the changed values , N : for correcting the tree using inorder

Aux. Space Req. : O(N + 2logN)
N for storing inorder traversa, 2logN for recursive stack for two times call of inorder
*/
void recover(TreeNode *root, int &i, vector<int> &inord)
{
    if (root == nullptr || i >= inord.size())
    {
        return;
    }

    recover(root->left, i, inord);

    if (root->data != inord[i])
    {
        root->data = inord[i];
    }
    i++;
    recover(root->right, i, inord);
}
void recoverBST1(TreeNode *root)
{
    vector<int> inord;

    inorder(root, inord);

    int ind1 = -1, ind2 = -1;

    for (int i = 1; i < inord.size(); i++)
    {
        if (inord[i] < inord[i - 1])
        {
            if (ind1 == -1)
            {
                ind1 = i - 1;
            }
            ind2 = i;
        }
    }
    swap(inord[ind1], inord[ind2]);
    int ind = 0;
    recover(root, ind, inord);
}

void recoverBST2(TreeNode *root)
{
    TreeNode *curr = root;
    TreeNode *first, *second, *last;
    first = new TreeNode(INT_MIN);
    second = nullptr;
    last = nullptr;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // Visit current node
            if (curr->data < first->data)
            {
                if (second == nullptr)
                {
                    second = first;
                }
                last = curr;
            }

            first = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;

            while (prev->right != nullptr && prev->right != curr)
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

                // Visit current node
                if (curr->data < first->data)
                {
                    if (second == nullptr)
                    {
                        second = first;
                    }
                    last = curr;
                }

                first = curr;
                curr = curr->right;
            }
        }
    }

    if (second != nullptr && last != nullptr)
    {
        swap(second->data, last->data);
    }
}

int main()
{

    vector<int> tree = {20, 5, 15, 2, 8, 12, 18, 1, 3, 6, 9, 11, 14, 16, 10,
                        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    TreeNode *root = buildTree(tree);

    vector<int> inorder1;
    inorder(root, inorder1);
    cout << "Inorder before recovery : ";
    display(inorder1);

    recoverBST2(root);

    vector<int> inorder2;
    inorder(root, inorder2);
    cout << "Inorder after recovery : ";

    display(inorder2);

    return 0;
}
