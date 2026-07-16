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

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void allTraversals(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<pair<TreeNode *, int>> st;
    vector<int> preOrder, inOrder, postOrder;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is part for pre order
        // increment 1 to 2
        // push the left side of the tree

        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }

        // this part is for in order
        // increment 2 to 3
        // push right side of the tree
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }

        // dont push it back again
        else
        {
            postOrder.push_back(it.first->data);
        }
    }

    cout << "Pre Order  : ";
    display(preOrder);

    cout << "In Order   : ";
    display(inOrder);

    cout << "Post Order : ";
    display(postOrder);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    allTraversals(root);

    return 0;
}