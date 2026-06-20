/*
Problem Name : Delete the middle node of the Linked List
Problem Description : Given a linked list , delete the middle node of the linked list
Note : In case of the two middle nodes , delete the second middle node
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

/*
Intuition : Use two pointer concept to find the middle node , also keep track of previous node so
that we can delete middle node and connect the prev node to next node of middle node

Algorithm Used : Optimal
Time Complexity : O(N/2)
Aux. Space Req. : O(1)
*/

Node *deleteMiddleOfLL1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = arrayToLL(arr);
    display(head);

    head = deleteMiddleOfLL1(head);
    display(head);

    return 0;
}