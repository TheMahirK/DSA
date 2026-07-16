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

/*
Intuition : Use in order traversal (morris traversal or recursive traversal), keeping track of current node (Node *node in this case)
Whenever first violation of increasing order happens , we store the violating node in a variable (Node *first in this case)
and the last violation is stored in (Node *second in this case), after full traversal we swap the values of the both nodes
to recover the BST in valid form

Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

void recoverBST2(TreeNode *root)
{
    TreeNode *curr = root;
    TreeNode *node, *first, *second;
    node = new TreeNode(INT_MIN);
    first = nullptr;
    second = nullptr;

    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            // Visit current node
            if (curr->data < node->data)
            {
                if (first == nullptr)
                {
                    first = node;
                }
                second = curr;
            }

            node = curr;
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
                if (curr->data < node->data)
                {
                    if (first == nullptr)
                    {
                        first = node;
                    }
                    second = curr;
                }

                node = curr;
                curr = curr->right;
            }
        }
    }

    if (first != nullptr && second != nullptr)
    {
        swap(first->data, second->data);
    }
}

int main()
{

    vector<int> tree = {10, 5, 15, 2, 9, 12, 18, 1, 3, 6, 8, 11, 14, 16, 20,
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
