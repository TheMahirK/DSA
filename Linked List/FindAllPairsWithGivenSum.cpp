/*
Problem Name : Find all the pairs with Given sum in Sorted DLL
Problem Description : Given a sorted DLL , find all the pairs with given sum in the DLL
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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

Node *arrayToDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        c->next = temp;
        temp->prev = c;
        c = c->next;
    }
    return head;
}

vector<pair<int, int>> findPairs1(Node *head, int sum)
{
    vector<pair<int, int>> ans;

    if (head == nullptr || head->next == nullptr)
    {
        return ans;
    }

    Node *c1 = head;

    while (c1 != nullptr)
    {
        int val1 = c1->data;

        if (val1 > sum)
            break;

        Node *c2 = c1->next;

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

Node *findTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *c = head;
    while (c->next != nullptr)
    {
        c = c->next;
    }
    return c;
}

vector<pair<int, int>> findPairs2(Node *head, int sum)
{
    vector<pair<int, int>> ans;
    Node *left = head;
    Node *right = findTail(head);

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
    Node *head = arrayToDLL(arr);
    display(head);

    vector<pair<int, int>> pairs = findPairs2(head, 8);

    for (auto pair : pairs)
    {
        cout << '{' << pair.first << ',' << pair.second << '}' << ' ';
    }

    return 0;
}