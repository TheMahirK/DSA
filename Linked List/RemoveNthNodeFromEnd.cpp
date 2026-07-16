/*

Problem Name : Remove Nth ListNode from End of the Linked List
Problem Description : Given a Linked List head and an integer N, remove the Nth node from
end of the Linked List and return head

Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
               https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

*/

/*

1. Algorithm Used :
   Time Complexity :
   Auxiliary Space Requirement :
   Intuition :
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
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode *arrToLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

/*

1. Algorithm Used : Brute force
   Time Complexity : O(2N) [in worst case]
   Auxiliary Space Requirement : O(1)
   Intuition : Count the total number of nodes , traverse from start and keep decreasing the count
   when reached at N , delete the next node
*/

ListNode *removeNthFromEnd1(ListNode *head, int n)
{
    if (head == nullptr)
    {
        return head;
    }

    int count = 0;
    ListNode *c = head;

    while (c != nullptr)
    {
        count++;
        c = c->next;
    }

    if (n == count)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    else if (n > count)
    {
        return head;
    }

    c = head;

    while (c != nullptr)
    {
        count--;

        if (count == n)
        {

            ListNode *temp = c->next;
            c->next = c->next->next;
            delete temp;
            break;
        }
        c = c->next;
    }
    return head;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Use two pointers , fast pointer n+1 nodes ahead of slow pointer
   when fast pointer reach end, the slow pointer reach one node before nth node from last
   delete nth node and return head

*/

ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    if (head == nullptr || n <= 0)
    {
        return head;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    int steps = 0;

    for (; steps < n && fast != nullptr; steps++)
    {
        fast = fast->next;
    }

    if (steps < n)
    {
        return head;
    }

    if (fast == nullptr)
    {

        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

int main()
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    ListNode *head = arrToLinkedList(arr);
    display(head);

    int n = 10;

    head = removeNthFromEnd2(head, n);
    display(head);

    return 0;
}