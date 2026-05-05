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

Node *arrToLinkedList(vector<int> &arr)
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

Node *reverseSinglyLinkedList1(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *c = head;
    stack<int> st;

    while (c != nullptr)
    {
        st.push(c->data);
        c = c->next;
    }
    c = head;
    while (c != nullptr)
    {
        int ele = st.top();
        st.pop();
        c->data = ele;
        c = c->next;
    }
    return head;
}

Node *reverseSinglyLinkedList2(Node *head)
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

int main()
{
    vector<int> arr = {12, 5, 7, 3, 2, 11};
    Node *head = arrToLinkedList(arr);

    display(head);

    head = reverseSinglyLinkedList1(head);
    display(head);

    return 0;
}