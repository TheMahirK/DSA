#include <iostream>
using namespace std;
class Node
{
    public :
        int data;
        Node* next;


    Node(int data, Node* next)
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

void display(Node* head)
{
    Node* c = head;
    while(c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

Node* arrToLinkedList(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* c = head;
    
    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

bool search(Node* head, int target)
{
    if(head == nullptr)
    {
        return false;
    }

    Node* c = head;

    while(c)
    {
        if(c->data == target)
        {
            return true;
        }
        c = c->next;
    }
    return false;
}


int main()
{
    vector<int> arr = {2,13,7,11,3,5};

    Node* head = arrToLinkedList(arr);

    display(head);

    int target = 3;
    bool result = search(head, target);

    if(result)
    {
        cout << target << " is present in the list";
    }
    else
    {
        cout << target << " is NOT present in the list";
    }

    return 0;
}