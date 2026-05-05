/*

Problem Name : Odd Even Linked List
Problem Description : Given a singly Linked List
Arrange the linked list such that all odd position elements come before all even position
elements without changing the order of all odd position elements and even position elements

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
   Auxiliary Space Requirement : O(N)
   Intuition : Store all odd position elements first in an array , then all even position elements
   Assign the values to all nodes from the array
*/

Node *oddEvenList1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    vector<int> ans;

    Node *c = head;

    while (c != nullptr && c->next != nullptr)
    {
        ans.push_back(c->data);
        c = c->next->next;
    }

    if (c != nullptr)
    {
        ans.push_back(c->data);
    }

    c = head->next;

    while (c != nullptr && c->next != nullptr)
    {
        ans.push_back(c->data);
        c = c->next->next;
    }

    if (c != nullptr)
    {
        ans.push_back(c->data);
    }

    c = head;

    for (int i = 0; i < ans.size(); i++)
    {
        c->data = ans[i];
        c = c->next;
    }

    return head;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(2 * (N/2)) = O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : link all odd position elements to odd pointer, link all even position elements to even
   pointer, after this link last element of odd to first element of even
*/

Node *oddEvenList2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 7, 3, 2, 11, 16};
    Node *head = arrToLinkedList(arr);

    display(head);

    head = oddEvenList2(head);
    display(head);

    return 0;
}