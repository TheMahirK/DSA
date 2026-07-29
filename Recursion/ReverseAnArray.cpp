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

void reverse(int index, vector<int> &arr)
{
    if (index >= arr.size() / 2)
    {
        return;
    }
    swap(arr[index], arr[arr.size() - index - 1]);
    reverse(index + 1, arr);
}

void reverseArray(vector<int> &arr)
{
    reverse(0, arr);
}

int main()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    display(arr);

    reverseArray(arr);

    display(arr);

    return 0;
}