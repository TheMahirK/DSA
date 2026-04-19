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

int bSR(vector<int> &arr, int x, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }

    else if (x < arr[mid])
    {
        return bSR(arr, x, low, mid - 1);
    }

    else
    {
        return bSR(arr, x, mid + 1, high);
    }
}

int binarySearchRecursive(vector<int> &arr, int x)
{
    int n = arr.size();
    return bSR(arr, x, 0, n);
}

int binarySearchIterative(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        else if (x < arr[mid])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    int x = 0;

    display(arr);

    int index = binarySearchRecursive(arr, x);

    if (index >= 0)
    {
        cout << x << " found at index : " << index << endl;
    }

    else
    {
        cout << x << " not found in array" << endl;
    }

    return 0;
}