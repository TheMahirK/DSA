/*
Problem Name : Find Length of Loop in given linked list
Problem Description : Given the head of a linked list , if there is a loop in the linked list
return the length of the loop
Otherwise return 0
*/

#include <iostream>
#include <unordered_map>
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

/*
Intuition : Store node along with distance of each node from the start of the list , if loop exists
Loop length = current distance of node - previous distance

Algorithm Used : Brute force
Time Complexity : O(N)
Aux. Space Req. : O(N)

*/

int lengthOfLoop1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }

    Node *c = head;
    int dist = 1;
    unordered_map<Node *, int> mpp;

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

int getLength(Node *slow, Node *fast)
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

int lengthOfLoop2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

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

    Node *first = new Node(1);
    Node *head = first;

    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);
    Node *seventh = new Node(7);

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