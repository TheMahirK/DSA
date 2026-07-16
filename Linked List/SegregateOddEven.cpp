/*

Problem Name : Segregate Evens and Odds in a Linked List
Problem Description : Given a singly Linked List
Arrange the linked list such that all even elements come before all odd
elements without changing the order of all even elements and odd elements

Problem Link : https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

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

1. Algorithm Used : Brute Force
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(N)
   Intuition : Store all odd elements and even elements in their respective arrays
   In second iteration assign each node elements from the respective arrays
*/

ListNode *segregateEvenOdd1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> odd;
    vector<int> even;
    ListNode *c = head;

    while (c != nullptr)
    {
        if (c->data % 2 == 0)
        {
            even.push_back(c->data);
        }
        else
        {
            odd.push_back(c->data);
        }
        c = c->next;
    }

    c = head;

    for (int i = 0; i < even.size(); i++)
    {
        c->data = even[i];
        c = c->next;
    }

    for (int i = 0; i < odd.size(); i++)
    {
        c->data = odd[i];
        c = c->next;
    }

    return head;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(2 * (N/2)) = O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : link all odd elements to odd pointer, link all even elements to even
   pointer, after this link last element of even to first element of odd
*/

ListNode *segregateEvenOdd2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *even = new ListNode(-1);
    ListNode *evenHead = even;

    ListNode *odd = new ListNode(-1);
    ListNode *oddHead = odd;

    ListNode *curr = head;

    while (curr != nullptr)
    {
        if (curr->data % 2 == 0)
        {
            even->next = curr;
            even = even->next;
        }
        else
        {
            odd->next = curr;
            odd = odd->next;
        }

        curr = curr->next;
    }

    odd->next = nullptr;
    even->next = oddHead->next;

    return evenHead->next;
}

int main()
{
    vector<int> arr = {12, 5, 7, 3, 2, 11, 16};
    ListNode *head = arrToLinkedList(arr);

    display(head);

    head = segregateEvenOdd2(head);
    display(head);

    return 0;
}