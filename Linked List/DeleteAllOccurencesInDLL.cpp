/*
Problem Name : Delete all occurences of key in a DLL
Problem Description : Given a DLL and a key value , delete all the occurence of key value in DLL
and return the updated LL
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int data, ListNode *next = nullptr, ListNode *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

void display(ListNode *head)
{
    ListNode *c = head;
    while (c != nullptr)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode *arrayToLL(vector<int> &arr)
{
    int n = arr.size();
    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
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

ListNode *deleteAllOccurences(ListNode *head, int key)
{
    ListNode *c = head;

    while (c != nullptr)
    {
        if (c->data == key)
        {
            if (c == head)
            {
                head = c->next;
            }
            ListNode *nextNode = c->next;
            ListNode *prevNode = c->prev;

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

    ListNode *head = arrayToLL(arr);
    display(head);

    head = deleteAllOccurences(head, 0);
    display(head);

    return 0;
}