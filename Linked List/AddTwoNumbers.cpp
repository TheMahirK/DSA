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

Node *addTwoNumbers1(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    else if (head2 == nullptr)
    {
        return head1;
    }

    Node *dummy = new Node(-1);
    Node *c = dummy;

    Node *c1 = head1;
    Node *c2 = head2;

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

        Node *temp = new Node(carry % 10);
        c->next = temp;
        c = c->next;
        carry = carry / 10;
    }

    if (carry)
    {
        c->next = new Node(carry);
    }
    return dummy->next;
}

int main()
{

    vector<int> arr1 = {5, 7, 4};
    vector<int> arr2 = {6, 9, 8};

    Node *head1 = arrayToLL(arr1);
    display(head1);

    Node *head2 = arrayToLL(arr2);
    display(head2);

    Node *head = addTwoNumbers1(head1, head2);
    display(head);

    return 0;
}