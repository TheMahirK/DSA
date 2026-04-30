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

int countNodes(Node *head)
{
    Node *c = head;
    int count = 0;

    while (c)
    {
        count++;
        c = c->next;
    }

    return count;
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

Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *insertAtBegin(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *temp = new Node(val);

    if (head == nullptr)
        return temp;

    Node *c = head;
    while (c->next)
        c = c->next;

    c->next = temp;
    return head;
}

Node *insertAtPos(Node *head, int pos, int val)
{
    if (pos == 1)
    {
        return insertAtBegin(head, val);
    }

    Node *c = head;

    for (int i = 1; i <= pos - 2; i++)
    {
        if (c == nullptr)
        {
            return head;
        }
        c = c->next;
    }
    Node *temp = new Node(val);
    temp->next = c->next;
    c->next = temp;
    return head;
}

Node *deleteAtBegin(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    else if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *c = head;

    while (c->next->next)
    {
        c = c->next;
    }
    Node *temp = c->next;
    c->next = nullptr;
    delete temp;
    return head;
}

Node *deleteAtPos(Node *head, int pos)
{
    if (head == nullptr)
    {
        return head;
    }
    if (pos == 1)
    {
        return deleteAtBegin(head);
    }

    Node *c = head;

    for (int i = 1; i <= pos - 2; i++)
    {
        if (c->next == nullptr)
        {
            return head;
        }
        c = c->next;
    }

    if (c->next == nullptr)
    {
        return head;
    }

    Node *temp = c->next;
    c->next = c->next->next;
    delete temp;
    return head;
}

Node *deleteValue(Node *head, int val)
{
    while (head != nullptr && head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr)
    {
        return head;
    }

    Node *c = head;

    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            Node *temp = c->next;
            c->next = c->next->next;
            delete temp;
        }
        else
        {
            c = c->next;
        }
    }

    return head;
}

Node *insertBeforeValue(Node *head, int val, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    else if (head->data == val)
    {
        return new Node(x, head);
    }

    Node *c = head;

    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            Node *temp = new Node(x);
            temp->next = c->next;
            c->next = temp;
            break;
        }
        c = c->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 7, 3, 2, 11};
    Node *head = arrToLinkedList(arr);

    display(head);

    int totalNodes = countNodes(head);
    cout << "Total Nodes : " << totalNodes << endl;

    head = insertBeforeValue(head, 2, 100);
    display(head);

    return 0;
}