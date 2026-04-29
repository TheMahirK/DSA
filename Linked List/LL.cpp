#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data, Node<T> *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
void display(Node<T> *head)
{
    Node<T> *c = head;
    while (c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

template <typename T>
int countNodes(Node<T> *head)
{
    Node<T> *c = head;
    int count = 0;

    while (c)
    {
        count++;
        c = c->next;
    }

    return count;
}

template <typename T>
Node<T> *arrToLinkedList(vector<T> &arr)
{
    if (arr.empty())
        return nullptr;

    Node<T> *head = new Node<T>(arr[0]);
    Node<T> *c = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node<T> *temp = new Node<T>(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

template <typename T>
Node<T> *middleNode(Node<T> *head)
{
    Node<T> *slow = head;
    Node<T> *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
Node<T> *insertAtBegin(Node<T> *head, T val)
{
    Node<T> *temp = new Node<T>(val);
    temp->next = head;
    return temp;
}

template <typename T>
Node<T> *insertAtEnd(Node<T> *head, T val)
{
    Node<T> *temp = new Node<T>(val);

    if (head == nullptr)
        return temp;

    Node<T> *c = head;
    while (c->next)
        c = c->next;

    c->next = temp;
    return head;
}

template <typename T>
Node<T> *insertAtPos(Node<T> *head, int pos, T val)
{
    if(pos == 1)
    {
        return insertAtBegin(head, val);
    }

    Node<T> *c = head;

    for(int i=1; i<=pos-2; i++)
    {
        if(c == nullptr)
        {
            return head;
        }
        c = c->next;
    }
    Node<T> *temp = new Node<T>(val);
    temp->next = c->next;
    c->next = temp;
    return head;
}

template <typename T>
Node<T> *deleteAtBegin(Node<T> *head)
{
    if(head == nullptr)
    {
        return head;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
    return head;
}

template <typename T>
Node<T> *deleteAtEnd(Node<T> *head)
{
    if(head == nullptr)
    {
        return head;
    }

    else if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node<T> *c = head;

    while(c->next->next)
    {
        c = c->next;
    }
    Node<T> *temp = c->next;
    c->next = nullptr;
    delete temp;
    return head;
}

template <typename T>

Node<T> *deleteAtPos(Node<T> *head, int pos)
{
    if(head == nullptr)
    {
        return head;
    }
    if(pos == 1)
    {
        return deleteAtBegin(head);
    }

    Node<T> *c = head;

    for(int i=1; i<=pos-2; i++)
    {
        if(c->next == nullptr)
        {
            return head;
        }
        c = c->next;
    }
    
    if(c->next == nullptr)
    {
        return head;
    }

    Node<T> *temp = c->next;
    c->next = c->next->next;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    Node<int> *head = arrToLinkedList(arr);

    display(head);

    int totalNodes = countNodes(head);
    cout << "Total Nodes : " << totalNodes << endl;

    head = insertAtBegin(head, 0);
    display(head);

    head = insertAtEnd(head, 7);
    display(head);

    head = insertAtPos(head, 9, 8);
    display(head);

    head = deleteAtBegin(head);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    head = deleteAtPos(head, 7);
    display(head);

    return 0;
}