/*

Problem Name : Sort a Linked List which contains 0s, 1s and 2s only
Problem Description : Given a singly Linked List which contain 0s, 1s and 2s only in any order
Sort the linked list and return the new head

Problem Link : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

Node *arrToLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)
   Intuition : Keep count of 0s, 1s and 2s.
   In second iteration assign the values to nodes in respective order for respective count times
*/

Node *segregate1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int count0 = 0, count1 = 0, count2 = 0;

    Node *c = head;

    while (c != nullptr)
    {
        if (c->data == 0)
        {
            count0++;
        }
        else if (c->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        c = c->next;
    }

    c = head;

    while (c != nullptr)
    {
        if (count0 > 0)
        {
            c->data = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            c->data = 1;
            count1--;
        }
        else
        {
            c->data = 2;
            count2--;
        }
        c = c->next;
    }

    return head;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : link all zeroes to zero pointer , 1s to one pointer , 2s to two pointer
   Link all last node of zeroes to head of 1s , link last node of 1s to head of 2s
   Make last node of 2s nullptr
*/

Node *segregate2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *zeroHead = new Node(-1);
    Node *zero = zeroHead;
    Node *oneHead = new Node(-1);
    Node *one = oneHead;
    Node *twoHead = new Node(-1);
    Node *two = twoHead;

    Node *c = head;

    while (c != nullptr)
    {
        if (c->data == 0)
        {
            zero->next = c;
            if (zero->next != nullptr)
            {
                zero = zero->next;
            }
        }
        else if (c->data == 1)
        {
            one->next = c;
            if (one->next != nullptr)
            {
                one = one->next;
            }
        }
        else
        {
            two->next = c;
            if (two->next != nullptr)
            {
                two = two->next;
            }
        }
        c = c->next;
    }
    two->next = nullptr;
    zero->next = oneHead->next;
    one->next = twoHead->next;
    return zeroHead->next;
}

int main()
{
    vector<int> arr = {1, 2, 0, 0, 0, 1, 2, 0, 1, 1, 0, 2};
    Node *head = arrToLinkedList(arr);

    display(head);

    head = segregate2(head);
    display(head);

    return 0;
}