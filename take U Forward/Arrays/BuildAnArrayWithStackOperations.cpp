#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<string> &stack)
{
    for (auto operation : stack)
    {
        cout << operation << ' ';
    }
    cout << endl;
}

vector<string> buildArray(vector<int> &arr, int n)
{
    vector<string> ans;
    int start = 0;

    for (int i = 1; i <= n; i++)
    {
        if (arr[start] == i)
        {
            ans.push_back("Push");
            start++;
        }
        else
        {
            ans.push_back("Push");
            ans.push_back("Pop");
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {2, 3, 6, 9};
    display(arr);

    // vector<string> operations = {"Push","Push","Pop","Push","Push","Push","Pop","Push","Pop",
    //     "Push","Push","Pop","Push","Pop","Push"};
    // display(operations);

    int n = 9;
    vector<string> ops = buildArray(arr, n);
    display(ops);

    return 0;
}