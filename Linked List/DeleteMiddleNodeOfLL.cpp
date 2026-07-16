/*
Problem Name : Delete the middle node of the Linked List
Problem Description : Given a linked list , delete the middle node of the linked list
Note : In case of the two middle nodes , delete the second middle node
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next)
    {
        this->data = data;
        this->next = next;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
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

ListNode *deleteMiddleOfLL1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

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
    ListNode *head = arrayToLL(arr);
    display(head);

    head = deleteMiddleOfLL1(head);
    display(head);

    return 0;
}