/*
Problem Name : Remove Duplicates from sorted DLL
Problem Description : Given a sorted DLL , remove all the duplicates from the DLL
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

Node *arrayToDLL(vector<int> &arr)
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
Intuition : Keep the first occurence , skip and delete the duplicate occurences , make connection to
the next node which is not duplicate of current node
Repeat this process for all nodes

Algorithm Used : Optimal
Time Complexity : O(N)
Aux. Space Req. : O(1)
*/

Node *removeDuplicates(Node *head)
{
    Node *c = head;

    while (c != nullptr && c->next != nullptr)
    {
        Node *nextNode = c->next;

        while (nextNode != nullptr && nextNode->data == c->data)
        {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }

        c->next = nextNode;

        if (nextNode != nullptr)
            nextNode->prev = c;
        c = c->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 7, 7};

    Node *head = arrayToDLL(arr);
    display(head);

    head = removeDuplicates(head);
    display(head);

    return 0;
}