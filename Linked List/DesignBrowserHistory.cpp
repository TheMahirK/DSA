#include <iostream>
#include <string>
#include <climits>
using namespace std;


// Implementation of a DLL
class ListNode
{
public:
    string data;
    ListNode *next;
    ListNode *back;

    ListNode(string x, ListNode *next = nullptr, ListNode *back = nullptr)
    {
        data = x;
        this->next = next;
        this->back = back;
    }
};


// Implementation of browser class
class BrowserHistory
{
private:
    ListNode *currentPage;

public:
    BrowserHistory(string homepage)
    {
        currentPage = new ListNode(homepage);
    }

    // Destructor
    ~BrowserHistory()
    {
        // Move to homepage
        while (currentPage->back)
            currentPage = currentPage->back;

        // Delete entire list
        while (currentPage)
        {
            ListNode *temp = currentPage;
            currentPage = currentPage->next;
            delete temp;
        }
    }

    void visit(string url)
    {
        // Delete forward history
        ListNode *temp = currentPage->next;

        while (temp)
        {
            ListNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        currentPage->next = nullptr;

        ListNode *newNode = new ListNode(url);
        newNode->back = currentPage;
        currentPage->next = newNode;
        currentPage = newNode;
    }

    string back(int steps)
    {
        while (steps > 0 && currentPage->back)
        {
            currentPage = currentPage->back;
            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps)
    {
        while (steps > 0 && currentPage->next)
        {
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->data;
    }

    string getCurrentPage()
    {
        return currentPage->data;
    }

    void display()
    {
        cout << "\n==============================\n";
        cout << "Current Page : " << getCurrentPage() << endl;
        cout << "==============================\n";
    }
};

int main()
{
    string homepage = "google.com";
    BrowserHistory browser(homepage);

    int choice = 0;
    string url;

    while (choice != 5)
    {
        browser.display();

        cout << "1. Next Website\n";
        cout << "2. Previous Website\n";
        cout << "3. Visit New Website\n";
        cout << "4. Go to Homepage\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            browser.forward(1);
            break;

        case 2:
            browser.back(1);
            break;

        case 3:
            cout << "Enter website URL: ";
            cin >> url;
            browser.visit(url);
            break;

        case 4:
            browser.back(INT_MAX);
            break;

        case 5:
            cout << "Thanks for using the browser.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}