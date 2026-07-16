/*

Problem Name : Add 2 Numbers
Problem Description : Given two numbers in in reverse order in form of two linked lists

like 475 in form 5->7->4->NULL
and  896 in form 6->9->8->NULL

add two numbers and return them in the same form (reverse ordered linked list)

that is
1371 in form 1->7->3->1->NULL

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
Intuition : Since the answer has to be in reversed order only and no leading zeroes are there in both
the lists , we can start adding from left side (from heads) of both linked lists, carrying any carryover

Algorithm Used : Optimal
Time Complexity : O(max(N1,N2)), N1 = no. of digits in first number , N2 = no. of digits in second number
Auxiliary Space Requirement : O(max(N1, N2)) for storing and returing the answer;
*/

ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    else if (head2 == nullptr)
    {
        return head1;
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *c = dummy;

    ListNode *c1 = head1;
    ListNode *c2 = head2;

    int carry = 0;

    while (c1 != nullptr || c2 != nullptr)
    {
        if (c1)
        {
            carry += c1->data;
            c1 = c1->next;
        }
        if (c2)
        {
            carry += c2->data;
            c2 = c2->next;
        }

        ListNode *temp = new ListNode(carry % 10);
        c->next = temp;
        c = c->next;
        carry = carry / 10;
    }

    if (carry)
    {
        c->next = new ListNode(carry);
    }
    return dummy->next;
}

int main()
{

    vector<int> arr1 = {5, 7, 4};
    vector<int> arr2 = {6, 9, 8};

    ListNode *head1 = arrayToLL(arr1);
    display(head1);

    ListNode *head2 = arrayToLL(arr2);
    display(head2);

    ListNode *head = addTwoNumbers(head1, head2);
    display(head);

    return 0;
}