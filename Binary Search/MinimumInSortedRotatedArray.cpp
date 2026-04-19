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

int findMin(vector<int>& arr)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int mini = arr[0];

    while(low <= high)
    {
        int mid = (high + (low-high)/2);

        if(arr[mid] < mini)
        {
            mini = arr[mid];
        }
        
        if(arr[mid] > mini)
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
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
    display(arr);

    cout << findMin(arr);

    return 0;
}