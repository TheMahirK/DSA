/*
Problem Name : Intersection in Y shaped Linked List
Problem Description : Given two linked lists connected like a Y shape, find the first common node of
the both linked lists (find the intersection)

Note : If there is no intersection , return nullptr
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

/*
Intuition : Store the Pointer and value of one linked list in an unordered map
When traveresing the second linked list , keep on checking in map for matching condition
When we find match , we find the intersection node

Algorithm Used : Brute Force
Time Complexity : O(N1) + O(N2) , N1 = no. of nodes in first LL , N2 = no. of nodes in second LL
Aux. Space Req. : O(N1) or O(N2)

*/

ListNode *findIntersectionNode1(ListNode *head1, ListNode *head2)
{
    unordered_map<ListNode *, int> mpp;

    ListNode *c1 = head1;

    while (c1 != nullptr)
    {
        mpp.insert({c1, c1->data});
        c1 = c1->next;
    }

    ListNode *c2 = head2;

    while (c2 != nullptr)
    {
        if (mpp.find(c2) != mpp.end())
        {
            return c2;
        }
        c2 = c2->next;
    }
    return nullptr;
}

/*
Intuition : Find the difference in number of nodes in both of the linked lists = d
Move the head Linked List with more number of nodes , d times ahead and then start comparison of
Nodes of both the linked lists

Algorithm Used : Better
Time Complexity :   O(2 * max(N1, N2))
Aux. Space Req. : O(1)

*/

ListNode *findIntersectionNode2(ListNode *head1, ListNode *head2)
{
    int n1 = 0, n2 = 0, d = 0;

    ListNode *c1 = head1;
    ListNode *c2 = head2;

    while (c1 != nullptr || c2 != nullptr)
    {
        if (c1)
        {
            n1++;
            c1 = c1->next;
        }
        if (c2)
        {
            n2++;
            c2 = c2->next;
        }
    }

    c1 = head1;
    c2 = head2;

    if (n1 > n2)
    {
        d = n1 - n2;

        for (int i = 1; i <= d && c1 != nullptr; i++)
        {
            c1 = c1->next;
        }
    }
    else
    {
        d = n2 - n1;

        for (int i = 1; i <= d && c2 != nullptr; i++)
        {
            c2 = c2->next;
        }
    }

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1 == c2)
        {
            return c1;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    return nullptr;
}

/*
Intuition : The difference between the number of nodes in both the lists is d
When the smaller list pointer reaches end , the larger list pointer is d nodes behind the smaller pointer
So upon reaching end , we send smaller pointer to head of larger list
and upon reaching end , we send larger pointer to head of smaller list
the distance of d nodes between both the pointers becomes 0 , and we can do usual traversal
This can be done in single while loop

Algorithm Used : Optimal
Time Complexity : O(N1 + N2)
Aux. Space Req. : O(1)
*/

ListNode *findIntersectionNode3(ListNode *head1, ListNode *head2)
{

    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    ListNode *c1 = head1;
    ListNode *c2 = head2;

    while (c1 != c2)
    {
        c1 = c1->next;
        c2 = c2->next;
        if (c1 == c2)
        {
            return c1;
        }

        if (c1 == nullptr)
        {
            c1 = head2;
        }

        if (c2 == nullptr)
        {
            c2 = head1;
        }
    }
    return c1;
}

int main()
{

    ListNode *first = new ListNode(1);
    ListNode *head1 = first;

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

    display(head1);

    ListNode *First = new ListNode(10);
    ListNode *Second = new ListNode(20);
    ListNode *Third = new ListNode(30);

    ListNode *head2 = First;
    First->next = Second;
    Second->next = Third;
    Third->next = fifth;

    display(head2);

    ListNode *intersectionNode = findIntersectionNode3(head1, head2);

    display(intersectionNode);

    return 0;
}