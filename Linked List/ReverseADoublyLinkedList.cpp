/*

Problem Name : Reverse a doubly Linked List
Problem Description : Given head of a doubly Linked List, goal is to reverse the Doubly Linked List
and return new head

*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int data, ListNode *next, ListNode *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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

ListNode *arrToDoublyLinkedList(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
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
ListNode *reverseDoublyLinkedList1(ListNode *head)
{
    stack<int> st;

    ListNode *c = head;

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

ListNode *reverseDoublyLinkedList2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *last = nullptr;
    ListNode *c = head;

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

    ListNode *head = arrToDoublyLinkedList(arr);

    display(head);

    head = reverseDoublyLinkedList2(head);
    display(head);

    return 0;
}