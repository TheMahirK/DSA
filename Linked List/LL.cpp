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

int countNodes(ListNode *head)
{
    ListNode *c = head;
    int count = 0;

    while (c)
    {
        count++;
        c = c->next;
    }

    return count;
}

ListNode *arrToLinkedList(vector<int> &arr)
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

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *insertAtBegin(ListNode *head, int val)
{
    ListNode *temp = new ListNode(val);
    temp->next = head;
    return temp;
}

ListNode *insertAtEnd(ListNode *head, int val)
{
    ListNode *temp = new ListNode(val);

    if (head == nullptr)
        return temp;

    ListNode *c = head;
    while (c->next)
        c = c->next;

    c->next = temp;
    return head;
}

ListNode *insertAtPos(ListNode *head, int pos, int val)
{
    if (pos == 1)
    {
        return insertAtBegin(head, val);
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
    ListNode *temp = new ListNode(val);
    temp->next = c->next;
    c->next = temp;
    return head;
}

ListNode *deleteAtBegin(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode *temp = head;
    head = head->next;
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

    while (c->next->next)
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
    if (pos == 1)
    {
        return deleteAtBegin(head);
    }

    ListNode *c = head;

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

    ListNode *temp = c->next;
    c->next = c->next->next;
    delete temp;
    return head;
}

ListNode *deleteValue(ListNode *head, int val)
{
    while (head != nullptr && head->data == val)
    {
        ListNode *temp = head;
        head = head->next;
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
            delete temp;
        }
        else
        {
            c = c->next;
        }
    }

    return head;
}

ListNode *insertBeforeValue(ListNode *head, int val, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    else if (head->data == val)
    {
        return new ListNode(x, head);
    }

    ListNode *c = head;

    while (c->next != nullptr)
    {
        if (c->next->data == val)
        {
            ListNode *temp = new ListNode(x);
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
    ListNode *head = arrToLinkedList(arr);

    display(head);

    int totalNodes = countNodes(head);
    cout << "Total Nodes : " << totalNodes << endl;

    head = insertBeforeValue(head, 2, 100);
    display(head);

    return 0;
}