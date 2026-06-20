/*
Problem Name : Delete all occurences of key in a DLL
Problem Description : Given a DLL and a key value , delete all the occurence of key value in DLL
and return the updated LL
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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
        temp->prev = c;
        c = temp;
    }
    return head;
}

/*
Intuition : do as what said in the problem while keeping in mind the edge cases and handling pointers carefully
Algorithm Used : Optimal
Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

Node *deleteAllOccurences(Node *head, int key)
{
    Node *c = head;

    while (c != nullptr)
    {
        if (c->data == key)
        {
            if (c == head)
            {
                head = c->next;
            }
            Node *nextNode = c->next;
            Node *prevNode = c->prev;

            if (nextNode != nullptr)
                nextNode->prev = prevNode;
            if (prevNode != nullptr)
                prevNode->next = nextNode;
            delete c;
            c = nextNode;
        }
        else
        {
            c = c->next;
        }
    }
    return head;
}

int main()
{
    vector<int> arr = {0, 0, 1, 0, 0, 2, 3, 0, 4, 5, 0, 6, 0, 0, 7, 0, 0};

    Node *head = arrayToLL(arr);
    display(head);

    head = deleteAllOccurences(head, 0);
    display(head);

    return 0;
}