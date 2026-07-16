#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T data;
        ListNode *next;
    };

    ListNode *head;

public:
    void display()
    {
        ListNode *c = head;

        while (c)
        {
            cout << c->data << ' ';
            c = c->next;
        }
        cout << endl;
    }

    LinkedList()
    {
        head = nullptr;
    }

    void insertAtHead(T value);
    void insertAtEnd(T value);

    void deleteAtEnd();
    void deleteBegin();

    void deleteKthNodeFromEnd(int k);
};

template <typename T>
void LinkedList<T>::insertAtHead(T value)
{
    ListNode *newNode = new ListNode;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T value)
{
    if (head == NULL)
    {
        head = new ListNode;
        head->data = value;
        head->next = NULL;
        return;
    }
    ListNode *c = head;
    while (c->next)
    {
        c = c->next;
    }
    ListNode *temp = new ListNode;
    temp->data = value;
    c->next = temp;
}

template <typename T>
void LinkedList<T>::deleteAtEnd()
{
    ListNode *c = head;
    while (c->next->next)
    {
        c = c->next;
    }

    delete c->next;
    c->next = NULL;
}

template <typename T>
void LinkedList<T>::deleteBegin()
{
    ListNode *temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::deleteKthNodeFromEnd(int k)
{
    if (head == NULL)
        return;

    ListNode *c1 = head;
    ListNode *c2 = head;

    // Move c2 k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (c2 == NULL)
            return; // k > length
        c2 = c2->next;
    }

    // If c2 becomes NULL → delete head
    if (c2 == NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Move both pointers
    while (c2->next != NULL)
    {
        c1 = c1->next;
        c2 = c2->next;
    }

    // Delete node
    ListNode *temp = c1->next;
    c1->next = temp->next;
    delete temp;
}
int main()
{

    LinkedList<int> list;

    for (int i = 1; i <= 20; i++)
    {
        list.insertAtEnd(i);
    }

    list.display();

    list.deleteKthNodeFromEnd(3);

    list.display();

    return 0;
}