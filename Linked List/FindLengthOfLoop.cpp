/*
Problem Name : Find Length of Loop in given linked list
Problem Description : Given the head of a linked list , if there is a loop in the linked list
return the length of the loop
Otherwise return 0
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
Intuition : Store node along with distance of each node from the start of the list , if loop exists
Loop length = current distance of node - previous distance

Algorithm Used : Brute force
Time Complexity : O(N)
Aux. Space Req. : O(N)

*/

int lengthOfLoop1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }

    ListNode *c = head;
    int dist = 1;
    unordered_map<ListNode *, int> mpp;

    while (c != nullptr)
    {
        if (mpp.find(c) != mpp.end())
        {
            return dist - mpp[c];
        }
        mpp[c] = dist;
        dist++;
        c = c->next;
    }
    return 0;
}

int getLength(ListNode *slow, ListNode *fast)
{
    int count = 1;
    fast = fast->next;
    while (fast != slow)
    {
        count++;
        fast = fast->next;
    }
    return count;
}

/*
Intuition : Use two pointer approach , if there is a loop in LL , the distance bw slow and fast
Nodes is d , with every iteration , this d decreases as slow moves 1 step , fast moves 2 steps
when d == 0 , slow and fast pointer overlap , which means there is a loop

If we detect the loop , we can find the length of loop by traversing once again in the loop

Algorithm Used : Optimal
Time Complexity : O(N)
Aux. Space Req. : O(1)

*/

int lengthOfLoop2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return getLength(slow, fast);
        }
    }
    return 0;
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

    int length = lengthOfLoop2(head);

    if (length)
    {
        cout << "LL have a cycle" << endl;
        cout << "The length of loop : " << length;
    }

    else
    {
        cout << "LL does not have cycle";
    }

    return 0;
}