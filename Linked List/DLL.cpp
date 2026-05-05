#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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

Node *arrToDoublyLinkedList(vector<int> &arr)
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

Node *insertAtBegin(Node *head, int x)
{
    if (head == nullptr)
    {
        return new Node(x);
    }
    Node *temp = new Node(x);
    head->prev = temp;
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int x)
{
    if (head == nullptr)
    {
        return new Node(x);
    }

    Node *c = head;

    while (c->next != nullptr)
    {
        c = c->next;
    }

    Node *temp = new Node(x);
    c->next = temp;
    temp->prev = c;
    return head;
}

Node *insertAtPos(Node *head, int pos, int x)
{
    if (head == nullptr)
    {
        if (pos == 1)
        {
            return insertAtBegin(head, x);
        }
        return head;
    }

    if (pos == 1)
    {
        return insertAtBegin(head, x);
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

    if (c == nullptr)
    {
        return head;
    }

    Node *temp = new Node(x);
    temp->next = c->next;
    if (c->next != nullptr)
    {
        c->next->prev = temp;
    }
    c->next = temp;
    temp->prev = c;
    return head;
}

Node *insertBeforeVal(Node *head, int val, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == val)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    Node *c = head;

    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            Node *temp = new Node(x);
            temp->next = c->next;
            c->next->prev = temp;
            temp->prev = c;
            c->next = temp;
            break;
        }
        c = c->next;
    }
    return head;
}

Node *deleteAtBegin(Node *head)
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
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
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

    while (c->next && c->next->next)
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
    else if (pos == 1)
    {
        return deleteAtBegin(head);
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

    if (c == nullptr || c->next == nullptr)
    {
        return head;
    }
    Node *temp = c->next;
    c->next = c->next->next;

    if (c->next)
    {
        c->next->prev = c;
    }
    delete temp;
    return head;
}

Node *deleteValue(Node *head, int val)
{
    while (head != nullptr && head->data == val)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
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
            if (c->next != nullptr)
            {
                c->next->prev = c;
            }
            delete temp;
        }
        else
        {
            c = c->next;
        }
    }
    return head;
}

int main()
{

    vector<int> arr = {11, 12, 5, 7, 3, 2, 11};
    // vector<int> arr = {1,11,11,11};

    Node *head = arrToDoublyLinkedList(arr);

    // Node *head = new Node(12);

    display(head);

    head = deleteValue(head, 11);
    display(head);

    return 0;
}