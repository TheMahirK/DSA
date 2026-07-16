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

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next)
    {
        this->data = data;
        this->next = next;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void display(ListNode *head)
{
    ListNode *c = head;
    while (c != nullptr)
    {

        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode *arrayToLL(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
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

ListNode *mergeTwoSortedLL(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    ListNode *dummy = new ListNode(-1);
    ListNode *currNode = dummy;

    ListNode *c1 = head1;
    ListNode *c2 = head2;

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

    ListNode *head1 = arrayToLL(arr1);
    ListNode *head2 = arrayToLL(arr2);

    display(head1);
    display(head2);

    ListNode *head = mergeTwoSortedLL(head1, head2);

    display(head);

    return 0;
}