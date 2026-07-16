#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode(int data, ListNode *next, ListNode *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
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

ListNode *arrToDoublyLinkedList(vector<int> &arr)
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

ListNode *insertAtBegin(ListNode *head, int x)
{
    if (head == nullptr)
    {
        return new ListNode(x);
    }
    ListNode *temp = new ListNode(x);
    head->prev = temp;
    temp->next = head;
    return temp;
}

ListNode *insertAtEnd(ListNode *head, int x)
{
    if (head == nullptr)
    {
        return new ListNode(x);
    }

    ListNode *c = head;

    while (c->next != nullptr)
    {
        c = c->next;
    }

    ListNode *temp = new ListNode(x);
    c->next = temp;
    temp->prev = c;
    return head;
}

ListNode *insertAtPos(ListNode *head, int pos, int x)
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

    ListNode *c = head;

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

    ListNode *temp = new ListNode(x);
    temp->next = c->next;
    if (c->next != nullptr)
    {
        c->next->prev = temp;
    }
    c->next = temp;
    temp->prev = c;
    return head;
}

ListNode *insertBeforeVal(ListNode *head, int val, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == val)
    {
        ListNode *temp = new ListNode(x);
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    ListNode *c = head;

    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            ListNode *temp = new ListNode(x);
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

ListNode *deleteAtBegin(ListNode *head)
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
    ListNode *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

ListNode *deleteAtEnd(ListNode *head)
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

    ListNode *c = head;

    while (c->next && c->next->next)
    {
        c = c->next;
    }

    ListNode *temp = c->next;
    c->next = nullptr;
    delete temp;
    return head;
}

ListNode *deleteAtPos(ListNode *head, int pos)
{
    if (head == nullptr)
    {
        return head;
    }
    else if (pos == 1)
    {
        return deleteAtBegin(head);
    }

    ListNode *c = head;

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
    ListNode *temp = c->next;
    c->next = c->next->next;

    if (c->next)
    {
        c->next->prev = c;
    }
    delete temp;
    return head;
}

ListNode *deleteValue(ListNode *head, int val)
{
    while (head != nullptr && head->data == val)
    {
        ListNode *temp = head;
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

    ListNode *c = head;
    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            ListNode *temp = c->next;
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

    ListNode *head = arrToDoublyLinkedList(arr);

    // ListNode *head = new ListNode(12);

    display(head);

    head = deleteValue(head, 11);
    display(head);

    return 0;
}