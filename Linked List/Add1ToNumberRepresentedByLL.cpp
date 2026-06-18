/*
Problem Name : Add 1 to number represented by a singly Linked List
Problem Description : Given a number N represented by a linked list in right order
Goal is to add 1 to the given number N , making it N+1
Return the linked list containing number N+1 in right order
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

Node *reverseSinglyLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *last = nullptr;
    Node *c = head;

    while (c != nullptr)
    {
        Node *nextNode = c->next;
        c->next = last;
        last = c;
        c = nextNode;
    }
    return last;
}

Node *arrayToLinkedList(vector<int> &arr)
{
    int n = arr.size();
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

/*
Intuition : Reverse the number (Linked List), add 1 to linked list from reversed head
Algorithm Used : 

*/

Node *addOne1(Node *head)
{
    head = reverseSinglyLL(head);

    int carry = 1;

    Node *c = head;

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
        Node *temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}

int main()
{

    vector<int> num = {9, 9, 9};

    Node *head = arrayToLinkedList(num);
    display(head);

    head = addOne1(head);
    display(head);

    return 0;
}