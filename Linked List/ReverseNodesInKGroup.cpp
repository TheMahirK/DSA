/*
Problem Name : Reverse Nodes in K group sizes
Problem Description : Given a singly LL , and a value K , reverse the nodes in groups of size k
return the modified LL

Ex. given LL
1->2->3->4->5->6->7->8->NULL , K = 3

Modified LL

3->2->1->6->5->4->7->8->NULL

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
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode *arrayToLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

ListNode *reverseLL(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *last = nullptr;
    ListNode *c = head;

    while (c != nullptr)
    {
        ListNode *nextNode = c->next;
        c->next = last;
        last = c;
        c = nextNode;
    }
    return last;
}

ListNode *getKthNode(ListNode *head, int k)
{
    if (k == 1 || head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int count = 1;
    ListNode *c = head;
    while (c != nullptr && count != k)
    {
        c = c->next;
        count++;
    }
    return c;
}

/*
Intuition : Follow the following steps
1. Get kth node
2. Set kth node->next = nullptr
3. Reverse from curr node till kth node

Store appropriate pointers for modified connections

Algorithm Used : Optimal
Time Complexity : O(2N)

N/k * k = N for get Kth node
N/k * k = N for reverseLL

total = 2N

Aux. Space Req. : O(1)
*/

ListNode *reverseNodesInKGroups(ListNode *head, int k)
{
    if (k == 1 || head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *currNode = head;
    ListNode *prevNode = nullptr;

    while (currNode != nullptr)
    {
        ListNode *kthNode = getKthNode(currNode, k);

        if (kthNode == nullptr)
        {
            if (prevNode)
            {
                prevNode->next = currNode;
            }
            break;
        }

        ListNode *nextNode = kthNode->next;
        kthNode->next = nullptr;

        reverseLL(currNode);

        if (currNode == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }

        prevNode = currNode;
        currNode = nextNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = arrayToLL(arr);
    display(head);

    int k = 3;

    head = reverseNodesInKGroups(head, k);

    display(head);

    return 0;
}