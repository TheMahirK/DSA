/*
Problem Name : Rotate a Linked List by K nodes
Problem Description : Given a singly LL and a value k , left rotate the LL by k nodes
and return the modified LL
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void display(Node *head)
{
    if (head == nullptr)
        return;
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

Node *getNthNode(Node *head, int n)
{
    int count = 1;
    Node *c = head;

    while (c->next != nullptr && count != n)
    {
        c = c->next;
        count++;
    }
    return c;
}

Node *leftRotateByKNodes(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *tailNode = head;
    int len = 1;

    while (tailNode->next != nullptr)
    {
        tailNode = tailNode->next;
        len++;
    }

    k = k % len;

    if (k == 0)
        return head;

    Node *newTail = getNthNode(head, len - k);
    tailNode->next = head;
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

Node *rightRotateByKNodes(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *tailNode = head;
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

    Node *newTail = getNthNode(head, len - k);
    tailNode->next = head;
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = arrayToLL(arr);
    display(head);

    int k = 16;

    head = rightRotateByKNodes(head, k);

    display(head);

    return 0;
}