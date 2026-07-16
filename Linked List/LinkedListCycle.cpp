/*
Problem Name : Linked List Cycle
Problem Description : Given the head of a linked list , return true if there is a cycle in
the Linked List , otherwise return false

*/

#include <iostream>
#include <unordered_map>
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

// void display(ListNode *head)
// {
//     ListNode *c = head;
//     while (c != nullptr)
//     {
//         cout << c->data << ' ';
//         c = c->next;
//     }
//     cout << endl;
// }

/*
Intuition : Store every node in a data structure (with exact memory address)
Whenever we see that any node already exists in the data structure (with same memory address)
we find that there is a loop in the list

Algorithm Used : Brute Force
Time Complexity : O(N)
Aux. Space Req. : O(N)

*/

bool checkCycle1(ListNode *head)
{
    if (head == nullptr)
    {
        return false;
    }

    ListNode *c = head;
    unordered_map<ListNode *, int> mpp;

    while (c != nullptr)
    {
        if (mpp.find(c) != mpp.end())
        {
            return true;
        }
        mpp.insert({c, c->data});
        c = c->next;
    }
    return false;
}

/*
Intuition : Use two pointer approach , if there is a loop in LL , the distance bw slow and fast
Nodes is d , with every iteration , this d decreases as slow moves 1 step , fast moves 2 steps
when d == 0 , slow and fast pointer overlap , which means there is a loop

if there is no loop , either fast reaches nullptr or fast->next reaches nullptr

Algorithm Used : Optimal
Time Complexity : ~ O(N)
Aux. Space Req. : O(1)
*/

bool checkCycle2(ListNode *head)
{
    if (head == nullptr)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    ListNode *first = new ListNode(1);
    ListNode *head = first;

    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);
    ListNode *sixth = new ListNode(6);
    ListNode *seventh = new ListNode(7);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    seventh->next = fourth;

    bool hasCycle = checkCycle2(head);

    if (hasCycle)
    {
        cout << "LL have a cycle";
    }

    else
    {
        cout << "LL does not have cycle";
    }

    return 0;
}