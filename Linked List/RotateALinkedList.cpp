/*
Problem Name : Rotate a Linked List by K nodes
Problem Description : Given a singly LL and a value k , left rotate the LL by k nodes
and return the modified LL
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void display(ListNode *head)
{
    if (head == nullptr)
        return;
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
Intuition : Follow these steps
Find length and last node of LL
k = k%len

Last node->next = head;

new last node = (len-k)th node

head = new last node->next

new last node ->next = nullptr

Algorithm Used : Optimal
Time Complexity : O(2N)
N for Tail node and length
~ N for new last node

Aux. Space Req. : O(1)
*/

ListNode *getNthNode(ListNode *head, int n)
{
    int count = 1;
    ListNode *c = head;

    while (c->next != nullptr && count != n)
    {
        c = c->next;
        count++;
    }
    return c;
}

ListNode *leftRotateByKNodes(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *tailNode = head;
    int len = 1;

    while (tailNode->next != nullptr)
    {
        tailNode = tailNode->next;
        len++;
    }

    k = k % len;

    if (k == 0)
        return head;

    ListNode *newTail = getNthNode(head, len - k);
    tailNode->next = head;
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

ListNode *rightRotateByKNodes(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *tailNode = head;
    int len = 1;

    while (tailNode->next != nullptr)
    {
        tailNode = tailNode->next;
        len++;
    }

    k = k % len;
    k = len - k;
    k = k % len;

    if (k == 0)
        return head;

    ListNode *newTail = getNthNode(head, len - k);
    tailNode->next = head;
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    ListNode *head = arrayToLL(arr);
    display(head);

    int k = 16;

    head = rightRotateByKNodes(head, k);

    display(head);

    return 0;
}