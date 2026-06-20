/*
Problem Name : First Node of the loop in Linked List / Linked List Cycle 2
Problem Description : Given a linked list , if there is a loop in the linked list , return the starting point of the loop
Otherwise return nullptr
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
Intuition : Store all nodes in a map , whenever we find that a node is repeated in the iteration , we know that there is
a cycle in the LL , the first node that gets repeated is the starting point of the loop

Algorithm Used : Brute Force
Time Complexity : O(N)
Aux. Space Req. : O(N)
*/

Node *getCycleStartPoint1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *c = head;
    unordered_map<Node *, int> mpp;

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

Node *getCycleStartPoint2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head;

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

    Node *startingPoint = getCycleStartPoint2(head);

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
