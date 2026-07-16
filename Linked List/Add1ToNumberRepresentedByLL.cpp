/*
Problem Name : Add 1 to number represented by a singly Linked List
Problem Description : Given a number N represented by a linked list in right order
Goal is to add 1 to the given number N , making it N+1
Return the linked list containing number N+1 in right order
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

ListNode *reverseSinglyLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *last = nullptr;
    ListNode *c = head;

    while (c != nullptr)
    {
        ListNode *nextNode = c->next;
        c->next = last;
        last = c;
        c = nextNode;
    }
    return last;
}

ListNode *arrayToLinkedList(vector<int> &arr)
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

/*
Intuition : Reverse the number (Linked List), add 1 to linked list from reversed head
Algorithm Used : 

*/

ListNode *addOne1(ListNode *head)
{
    head = reverseSinglyLL(head);

    int carry = 1;

    ListNode *c = head;

    while (c != nullptr && carry != 0)
    {
        int num = c->data + carry;
        c->data = num % 10;
        carry = num / 10;
        c = c->next;
    }

    head = reverseSinglyLL(head);

    if (carry)
    {
        ListNode *temp = new ListNode(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}

int main()
{

    vector<int> num = {9, 9, 9};

    ListNode *head = arrayToLinkedList(num);
    display(head);

    head = addOne1(head);
    display(head);

    return 0;
}