/*
Problem Name : Merge K Sorted Lists
Problem Description : Given a vector containing the heads of K sorted Lists , merge all k sorted Lists
into a single sorted list and return the merged list
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

void display(Node *head)
{
    if (head == nullptr)
        return;
    Node *c = head;

    while (c != nullptr)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

Node *arrayToLL(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *c = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

Node *merge(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    Node *dummy = new Node(-1);
    Node *c = dummy, *c1 = head1, *c2 = head2;

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

/*
Intuition : Merge all other lists into first list in sorted order (use concept of merging two sorted lists)
Algorithm Used : Better/Brute Force
Time Complexity : O(k * N^2)
Aux. Space Req. : O(1)
*/

Node *mergeKSortedLists1(vector<Node *> &lists)
{
    Node *head = lists[0];
    int k = lists.size();

    for (int i = 1; i < k; i++)
    {
        head = merge(head, lists[i]);
    }
    return head;
}

/*
Intuition : Use priority queue to store the heads of all lists, since all the lists are sorted , we only just need to merge
nodes which are from other lists. The priority queue stores the node with smallest value on top every time
We can repetetively store and pop nodes of lists in priority queue and keep linking changes as we proceed to ultimately
make a chain with all nodes of all linked together in a single sorted list

Algorithm Used : Optimal
Time Complexity : O(k log k) + O(N * k log k)
k log k : for insering k nodes in priority queue
N*k : for traversing all nodes
N = Avg. number of nodes in all lists
Aux. Space Req. : O(k)
for storing k nodes at a time in priority queue
*/
Node *mergeKSortedLists2(vector<Node *> &lists)
{
    int n = lists.size();
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (lists[i] != nullptr)
        {
            pq.push({lists[i]->data, lists[i]});
        }
    }

    Node *dummy = new Node(-1);
    Node *currNode = dummy;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (it.second->next)
        {
            pq.push({it.second->next->data, it.second->next});
        }
        currNode->next = it.second;
        currNode = currNode->next;
    }
    return dummy->next;
}

int main()
{
    int k = 4;
    vector<vector<int>> arr = {{1, 2, 4, 8, 16}, {1, 3, 9, 27}, {1, 4, 16}, {1, 5, 25}};

    vector<Node *> lists;

    for (int i = 0; i < k; i++)
    {
        Node *temp = arrayToLL(arr[i]);
        display(temp);
        lists.push_back(temp);
    }

    Node *head = mergeKSortedLists2(lists);
    display(head);

    return 0;
}