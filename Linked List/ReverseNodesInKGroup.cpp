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

void display(Node *head)
{
    Node *c = head;
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

Node *arrayToLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *last = nullptr;
    Node *c = head;

    while (c != nullptr)
    {
        Node *nextNode = c->next;
        c->next = last;
        last = c;
        c = nextNode;
    }
    return last;
}

Node *getKthNode(Node *head, int k)
{
    if (k == 1 || head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int count = 1;
    Node *c = head;
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

Node *reverseNodesInKGroups(Node *head, int k)
{
    if (k == 1 || head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *currNode = head;
    Node *prevNode = nullptr;

    while (currNode != nullptr)
    {
        Node *kthNode = getKthNode(currNode, k);

        if (kthNode == nullptr)
        {
            if (prevNode)
            {
                prevNode->next = currNode;
            }
            break;
        }

        Node *nextNode = kthNode->next;
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
    Node *head = arrayToLL(arr);
    display(head);

    int k = 3;

    head = reverseNodesInKGroups(head, k);

    display(head);

    return 0;
}