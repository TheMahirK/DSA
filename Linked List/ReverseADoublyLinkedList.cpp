/*

Problem Name : Reverse a doubly Linked List
Problem Description : Given head of a doubly Linked List, goal is to reverse the Doubly Linked List
and return new head

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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

Node *arrToDoublyLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        temp->prev = c;
        c = c->next;
    }
    return head;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(N)
   Intuition : Store the elements of DLL in a stack
   In second traversal , assign elements from stack top to bottom

*/
Node *reverseDoublyLinkedList1(Node *head)
{
    stack<int> st;

    Node *c = head;

    while (c != nullptr)
    {
        st.push(c->data);
        c = c->next;
    }

    c = head;

    while (c != nullptr)
    {
        int ele = st.top();
        st.pop();
        c->data = ele;
        c = c->next;
    }

    return head;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Instead of swapping the elements , just swap the links between nodes
   just like we swap two variables using a third variable
*/

Node *reverseDoublyLinkedList2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *last = nullptr;
    Node *c = head;

    while (c != nullptr)
    {
        last = c->prev;
        c->prev = c->next;
        c->next = last;
        c = c->prev;
    }
    return last->prev;
}

int main()
{

    vector<int> arr = {6, 11, 5, 7, 3, 2, 11};

    Node *head = arrToDoublyLinkedList(arr);

    display(head);

    head = reverseDoublyLinkedList2(head);
    display(head);

    return 0;
}