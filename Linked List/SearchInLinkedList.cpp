#include <iostream>
using namespace std;
class ListNode
{
    public :
        int data;
        ListNode* next;


    ListNode(int data, ListNode* next)
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

void display(ListNode* head)
{
    ListNode* c = head;
    while(c)
    {
        cout << c->data << ' ';
        c = c->next;
    }
    cout << endl;
}

ListNode* arrToLinkedList(vector<int>& arr)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* c = head;
    
    for(int i=1; i<arr.size(); i++)
    {
        ListNode* temp = new ListNode(arr[i]);
        c->next = temp;
        c = c->next;
    }
    return head;
}

bool search(ListNode* head, int target)
{
    if(head == nullptr)
    {
        return false;
    }

    ListNode* c = head;

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

    ListNode* head = arrToLinkedList(arr);

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