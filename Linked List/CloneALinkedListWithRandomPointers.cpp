/*
Problem Name : Clone a Linked List with random pointers
Problem Description : Given a linked list with two pointers 1) Next pointer 2) Random pointer
Make a deep copy of the the original Linked list
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *random;

    ListNode(int data, ListNode *next = nullptr, ListNode *random = nullptr)
    {
        this->data = data;
        this->next = next;
        this->random = random;
    }
};

void display(ListNode *head)
{
    ListNode *c = head;

    while (c != nullptr)
    {
        cout << '{' << c << ": " << c->data << " , ";
        if (c->random != nullptr)
        {
            cout << c->random << " : " << c->random->data << "} ";
        }
        else
        {
            cout << "NULL} ";
        }
        c = c->next;
    }
    cout << endl
         << endl;
}

/*
Intuition : Fistly make new node for each node in the given linked list
store in a map with key = original node , value = new node
In second traversal make connections for next and random pointers using data stored in the map

Algorithm Used : Brute force
Time Complexity : O(2N)
N : for making new nodes, N for making connections
Aux. Space Req. : O(2N)
N : for storing data in map, N : for returning the answer
*/

ListNode *makeDeepCopy1(ListNode *head)
{
    unordered_map<ListNode *, ListNode *> mpp;

    ListNode *c = head;

    while (c != nullptr)
    {
        ListNode *newNode = new ListNode(c->data);
        mpp[c] = newNode;
        c = c->next;
    }

    c = head;

    while (c != nullptr)
    {
        ListNode *copyNode = mpp[c];
        copyNode->next = mpp[c->next];
        copyNode->random = mpp[c->random];
        c = c->next;
    }
    return mpp[head];
}

ListNode *insertCopyInBetween(ListNode *head)
{
    ListNode *c = head;

    while (c != nullptr)
    {
        ListNode *nextNode = c->next;
        ListNode *copyNode = new ListNode(c->data);
        copyNode->next = nextNode;
        c->next = copyNode;
        c = nextNode;
    }

    return head;
}

ListNode *connectRandomPointers(ListNode *head)
{
    ListNode *c = head;
    while (c != nullptr)
    {
        ListNode *copyNode = c->next;

        if (c->random)
        {
            copyNode->random = c->random->next;
        }
        else
        {
            copyNode->random = nullptr;
        }
        c = c->next->next;
    }
    return head;
}

ListNode *getDeepCopyList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *dummy = new ListNode(-1);
    ListNode *c = dummy;

    while (temp != nullptr)
    {
        c->next = temp->next;
        c = c->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}

/*
Intuition : Follow these steps
1. Create deep copy nodes in between the existing nodes to preserve the relative positions
2. Connect deep copy nodes to their respective random pointers based on original random pointers
3. Remove the connections with original nodes to make two separate entities

Algorithm Used : Optimal
Time Complexity : O(3N)
N : for each step

Aux. Space Req. : O(N)
N : for returning the answer
*/
ListNode *makeDeepCopy2(ListNode *head)
{
    // Insert copy in between
    head = insertCopyInBetween(head);
    // connect random pointers

    head = connectRandomPointers(head);

    // Return deep copy
    return getDeepCopyList(head);
}

int main()
{
    ListNode *first = new ListNode(7);
    ListNode *head = first;

    ListNode *second = new ListNode(13);
    ListNode *third = new ListNode(11);
    ListNode *fourth = new ListNode(10);
    ListNode *fifth = new ListNode(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    first->random = nullptr;
    second->random = first;
    third->random = fifth;
    fourth->random = third;
    fifth->random = first;

    display(head);

    ListNode *copyHead = makeDeepCopy2(head);
    display(copyHead);

    return 0;
}