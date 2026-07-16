/*
Problem Name : Find all the pairs with Given sum in Sorted DLL
Problem Description : Given a sorted DLL , find all the pairs with given sum in the DLL
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int data, ListNode *next = nullptr, ListNode *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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

ListNode *arrayToDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        c->next = temp;
        temp->prev = c;
        c = c->next;
    }
    return head;
}

vector<pair<int, int>> findPairs1(ListNode *head, int sum)
{
    vector<pair<int, int>> ans;

    if (head == nullptr || head->next == nullptr)
    {
        return ans;
    }

    ListNode *c1 = head;

    while (c1 != nullptr)
    {
        int val1 = c1->data;

        if (val1 > sum)
            break;

        ListNode *c2 = c1->next;

        while (c2 != nullptr)
        {
            int val2 = c2->data;

            if (val1 + val2 == sum)
            {
                ans.push_back({val1, val2});
            }
            else if (val1 + val2 > sum)
                break;

            c2 = c2->next;
        }
        c1 = c1->next;
    }
    return ans;
}

ListNode *findTail(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *c = head;
    while (c->next != nullptr)
    {
        c = c->next;
    }
    return c;
}

vector<pair<int, int>> findPairs2(ListNode *head, int sum)
{
    vector<pair<int, int>> ans;
    ListNode *left = head;
    ListNode *right = findTail(head);

    while (left->data < right->data)
    {
        int val1 = left->data, val2 = right->data;
        if (val1 + val2 == sum)
        {
            ans.push_back({val1, val2});
            left = left->next;
            right = right->prev;
        }

        else if (val1 + val2 < sum)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head = arrayToDLL(arr);
    display(head);

    vector<pair<int, int>> pairs = findPairs2(head, 8);

    for (auto pair : pairs)
    {
        cout << '{' << pair.first << ',' << pair.second << '}' << ' ';
    }

    return 0;
}