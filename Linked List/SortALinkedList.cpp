/*
Problem Name : Sort a Linked List
Problem Description : Given a singly LL , sort the LL and return the head of the sorted List
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void display(ListNode *head)
{
    if (head == nullptr)
        return;
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
    if (n == 0)
        return nullptr;

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
Intuition : Store all elements in an array
Sort the array
Re-assign the elements to nodes from head in sequence

Note : this will sort the elements of a List , not the list itself
Meaning it will change the data values of lists , the linked list connections remain same
This will cause that the element previously stored at a memory location will be stored at different memory location
*/
ListNode *sortList1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    vector<int> arr;
    ListNode *c = head;

    while (c != nullptr)
    {
        arr.push_back(c->data);
        c = c->next;
    }

    sort(arr.begin(), arr.end());

    c = head;
    int i = 0;
    while (c != nullptr)
    {
        c->data = arr[i];
        i++;
        c = c->next;
    }
    return head;
}

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *mergeTwoSortedLists(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *c1 = head1, *c2 = head2, *c = dummy;

    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->data <= c2->data)
        {
            c->next = c1;
            c1 = c1->next;
        }
        else
        {
            c->next = c2;
            c2 = c2->next;
        }
        c = c->next;
    }

    if (c1)
    {
        c->next = c1;
    }
    else
    {
        c->next = c2;
    }
    return dummy->next;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *middleNode = findMiddle(head);
    ListNode *leftHead = head, *rightHead = middleNode->next;
    middleNode->next = nullptr;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return mergeTwoSortedLists(leftHead, rightHead);
}

/*
Intuition : Use merge sort concept
1. Recursively divide list into two parts until single elements remain
2. Merge the two parts using merge two sorted lists function using backtracking

Algorithm Used : Optimal
Time Complexity : O[log N * (N + N/2)]

log N for recursion , N for traversing N nodes , N/2 for finding middle

Aux. Space Req. : O(log N)
For stack because of recursion
*/

ListNode *sortList2(ListNode *head)
{
    return mergeSort(head);
}

int main()
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    ListNode *head = arrayToLL(arr);
    display(head);

    head = sortList2(head);

    display(head);

    return 0;
}