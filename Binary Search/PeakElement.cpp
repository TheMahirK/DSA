#include <iostream>
using namespace std;

void display(vector<int>& arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

int peakElement(vector<int>& arr)
{
    int n = arr.size();
    if(n == 1)
    {
        return 0;
    }

    if(arr[0] > arr[1])
    {
        return 0;
    }
    if(arr[n-1] > arr[n-2])
    {
        return n-1;
    }

    int low = 1, high = n-2;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        {
            return mid;
        }

        else if(arr[mid] > arr[mid-1])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }

    }
    return low;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,1,0,1,0};
    display(arr);

    int index = peakElement(arr);

    cout << index << " : " << arr[index] << endl;


    return 0;
}