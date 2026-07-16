/*
Problem Name : First ListNode of the loop in Linked List / Linked List Cycle 2
Problem Description : Given a linked list , if there is a loop in the linked list , return the starting point of the loop
Otherwise return nullptr
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

/*
Intuition : Store all nodes in a map , whenever we find that a node is repeated in the iteration , we know that there is
a cycle in the LL , the first node that gets repeated is the starting point of the loop

Algorithm Used : Brute Force
Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

ListNode *getCycleStartPoint1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    ListNode *c = head;
    unordered_map<ListNode *, int> mpp;

    while (c != nullptr)
    {
        if (mpp.find(c) != mpp.end())
        {
            return c;
        }
        mpp[c] = c->data;
        c = c->next;
    }
    return nullptr;
}

/*
Intuition : This algorithm is similar to Detection of loop in LL cycle and is also a combinationation of optimal soln
for intersection of Two linked lists

1. Detect loop using two pointers , slow and fast
2. When loop is detected , we whole loop as a separate LL and non Looped LL as separate LL
3. We find the intersecting node of the both LL , that is the node where Non Looped LL ends , and Loop starts which is the
starting point of the Loop

This algorithm can also be proved Mathematically

Algorithm Used : Optimal
Time Complexity : ~ O(2N)
*/

ListNode *getCycleStartPoint2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
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

    ListNode *startingPoint = getCycleStartPoint2(head);

    if (startingPoint != nullptr)
    {
        cout << "LL have a cycle" << endl;
        cout << "Starting point of the cycle : " << startingPoint->data;
    }

    else
    {
        cout << "LL does not have cycle";
    }

    return 0;
}
