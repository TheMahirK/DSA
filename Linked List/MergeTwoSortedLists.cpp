/*
Problem Name : Merge two sorted Linked Lists
Problem Description : Given heads of two different sorted Linked Lists
Merge both the sorted LLs in sorted manner, return the merged List

Ex. List1   : 0->2->4->5->6->7->9->NULL
    List2   : 1->3->5->8->NULL
Merged List : 0->1->2->3->4->5->5->6->7->8->9->NULL

Follow up : Try to do in O(1) space
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void display(Node *head)
{
    Node *c = head;
    while (c != nullptr)
    {

        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

Node *arrayToLL(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *c = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

/*
Intuition : Instead of forming a new LL , just change the links/pointers of existing LL so that we merge the both LL
without using any extra space
Used dummy node to simplify determining the start node

Algorithm Used : Optimal
Time Complexity : O(N)
N = N1 + N2
N1 = No. of nodes in List1 , N2 = No. of nodes in List2
Aux. Space Req. : O(1)
*/

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *dummy = new Node(-1);
    Node *currNode = dummy;

    Node *c1 = head1;
    Node *c2 = head2;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->data <= c2->data)
        {
            currNode->next = c1;
            c1 = c1->next;
        }

        else
        {
            currNode->next = c2;
            c2 = c2->next;
        }
        currNode = currNode->next;
    }

    if (c1)
    {
        currNode->next = c1;
    }

    else
    {
        currNode->next = c2;
    }
    return dummy->next;
}

int main()
{
    vector<int> arr1 = {0, 2, 4, 5, 6, 7, 9};
    vector<int> arr2 = {1, 3, 5, 8};

    Node *head1 = arrayToLL(arr1);
    Node *head2 = arrayToLL(arr2);

    display(head1);
    display(head2);

    Node *head = mergeTwoSortedLL(head1, head2);

    display(head);

    return 0;
}