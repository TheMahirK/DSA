/*
Problem Name : Flatten a Linked List
Problem Description : Given a custom type of LL where each node has next node and child nodes

Link : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *child;

    ListNode(int data, ListNode *next = nullptr, ListNode *child = nullptr)
    {
        this->data = data;
        this->next = next;
        this->child = child;
    }
};

void displayChild(ListNode *head)
{
    ListNode *c = head;

    while (c != nullptr)
    {
        cout << c->data << ' ';
        c = c->child;
    }
    cout << endl;
}

void display(ListNode *head)
{
    ListNode *c = head;

    while (c != nullptr)
    {
        displayChild(c);
        c = c->next;
    }
    cout << endl;
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *c = dummy;

    ListNode *c1 = head1, *c2 = head2;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->data < c2->data)
        {
            c->child = c1;
            c = c1;
            c1 = c1->child;
        }
        else
        {
            c->child = c2;
            c = c2;
            c2 = c2->child;
        }
        c->next = nullptr;
    }

    if (c1)
    {
        c->child = c1;
    }
    else
    {
        c->child = c2;
    }
    if (dummy->child)
    {
        dummy->child->next = nullptr;
    }
    return dummy->child;
}

/*
Intuition : Recursively go to last parent chain , merge last two parent chains into one parent chain
recursively repeat this for all chains , in last , all chains get merged into a single chain

Algorithm Used : Optimal
Time Complexity : O(M * N)
M : Width of LL
N : Height of LL (No. of children per Parent node)
Aux. Space Req/ : O(N)
Used by stack because of recursion

*/
ListNode *flattenLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *mergedHead = flattenLL(head->next);
    head = merge(head, mergedHead);
    return head;
}

int main()
{

    ListNode *Node1 = new ListNode(3);
    ListNode *head = Node1;
    ListNode *Node2 = new ListNode(2);
    ListNode *Child2_1 = new ListNode(10);
    Node2->child = Child2_1;

    Node1->next = Node2;

    ListNode *Node3 = new ListNode(1);
    ListNode *Child3_1 = new ListNode(7);
    ListNode *Child3_2 = new ListNode(11);
    ListNode *Child3_3 = new ListNode(12);

    Node2->next = Node3;
    Node3->child = Child3_1;
    Child3_1->child = Child3_2;
    Child3_2->child = Child3_3;

    display(head);

    head = flattenLL(head);

    display(head);

    return 0;
}
