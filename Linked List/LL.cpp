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

int countNodes(Node* head)
{
    Node* c = head;
    int count = 0;

    while(c)
    {
        count++;
        c = c->next;
    }

    return count;
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

Node* middleNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* insertAtBegin(Node* head, int x)
{
    if(head == nullptr)
    {
        Node* temp = new Node(x);
        return temp;
    }

    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

int main()
{
    // vector<int> arr = {};
    Node* head = new Node(1);
    // head = arrToLinkedList(arr);

    display(head);

    int totalNodes = countNodes(head);

    cout << "Total Nodes : " << totalNodes << endl;


    // Node* middle = middleNode(head);

    // display(middle);

    head = insertAtBegin(head,0);

    display(head);

    return 0;

}