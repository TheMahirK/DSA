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

int findMin(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int mini = arr[0];

    while (low <= high)
    {
        int mid = (high + low) / 2;
        cout << mid << endl;

        if (arr[mid] < mini)
        {
            mini = arr[mid];
        }

        if (arr[low] <= arr[mid])
        {
            low = mid+1;
        }

        else
        {
            high = mid-1;
        }
    }

    return mini;
}

int main()
{
    // vector<int> arr = {5, 6, 0, 5, 5, 5, 5, 5, 5, 5, 5};
    // vector<int> arr = {2,2,2,0,1};
    // vector<int> arr = {3,3,1};
    vector<int> arr = {10,1,10,10,10};
    display(arr);

    int minimum = findMin(arr);

    cout << "Minimum : " << minimum;

    return 0;
}