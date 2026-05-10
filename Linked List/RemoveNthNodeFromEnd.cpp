/*

Problem Name : Remove Nth Node from End of the Linked List
Problem Description : Given a Linked List head and an integer N, remove the Nth node from
end of the Linked List and return head

Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
               https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

*/

/*

1. Algorithm Used :
   Time Complexity :
   Auxiliary Space Requirement :
   Intuition :
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

1. Algorithm Used : Brute force
   Time Complexity : O(2N) [in worst case]
   Auxiliary Space Requirement : O(1)
   Intuition : Count the total number of nodes , traverse from start and keep decreasing the count
   when reached at N , delete the next node
*/

Node *removeNthFromEnd1(Node *head, int n)
{
    if (head == nullptr)
    {
        return head;
    }

    int count = 0;
    Node *c = head;

    while (c != nullptr)
    {
        count++;
        c = c->next;
    }

    if (n == count)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    else if (n > count)
    {
        return head;
    }

    c = head;

    while (c != nullptr)
    {
        count--;

        if (count == n)
        {

            Node *temp = c->next;
            c->next = c->next->next;
            delete temp;
            break;
        }
        c = c->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Node *head = arrToLinkedList(arr);
    display(head);

    int n = 8;

    head = removeNthFromEnd1(head, n);
    display(head);

    return 0;
}